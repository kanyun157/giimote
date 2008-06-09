// mii.h - Contains Mii related constants and functions.

#define MII_DATA_START 0xFCA
#define MII_DATA_END 0x15AA
#define MII_BLOCK_SIZE 0x2F0
#define MII_BLOCK_ADDRESS(b) (MII_DATA_START + (b) * MII_BLOCK_SIZE)
#define MII_DATA_LENGTH (MII_BLOCK_SIZE * 2)
#define MII_LENGTH 0x4a

#define MII_NAME_LENGTH				10
#define MII_CREATOR_NAME_LENGTH		10

#define MII_HEIGHT_MIN				0x00
#define MII_HEIGHT_MAX				0x7F

#define MII_WEIGHT_MIN				0x00
#define MII_WEIGHT_MAX				0x7F

#define poly 0x1021 // crc-ccitt mask

namespace GiiMoteLib {

	/// <summary>Dumps mii data from the Wii Remote</summary>
	/// <param name="fName">The file name</param>
	/// <param name="miiBlock">The mii block to dump from (1 or 2)</param>
	/// <param name="miiNumber">The mii number to dump (1-10, use 0 for entire block)</param>
	/// <returns>Success</returns>
	double GiiMote::wm_mii_data_dump(System::String^ fName, double miiBlock, double miiNumber)
	{
		int start, end;
		// unsigned char tData;
		int iReturn = 0;
		int miiNum = (int)miiNumber;
		if (miiNum < 0 || miiNum > 10 || miiBlock < 0 || miiBlock > 2)
		{
			return ( 0 );
		}
		int miiLoc = ((MII_LENGTH * (miiNum-1))*(miiNum!=0));
		int blockStart = MII_DATA_START + (MII_BLOCK_SIZE * (miiBlock==2));
		start = blockStart + miiLoc;
		if (miiNum == 0)
		{
			end = blockStart + MII_BLOCK_SIZE + ( (MII_BLOCK_SIZE) * (miiBlock==0) );
		}
		else
		{
			end = start + MII_LENGTH;
		}
		System::IO::FileStream^ miiFile = gcnew System::IO::FileStream(fName,System::IO::FileMode::Create);
		try
		{
			miiFile->Write(wc[wmIndex]->ReadData(start, end - start), 0, end - start);
		}
		catch (...)
		{
			iReturn = 0;
		}
		/*for(int i = start; i < end; i++)
		{
			try {
				tData = wc[wmIndex]->ReadData(i,1)[0];
			}
			catch (...) {
				delete miiFile;
				return ( -1 );
			}
			try {
				miiFile->WriteByte(tData);
			}
			catch (...) {
				delete miiFile;
				return ( 0 );
			}
		}*/
		miiFile->Close();
		delete miiFile;
		return ( (double)iReturn );
	}

	/// <summary>Injects mii data to the Wii Remote</summary>
	/// <param name="fName">The file name</param>
	/// <param name="miiBlock">The mii block to inject to</param>
	/// <param name="miiNumber">The mii number to inject (1-10)</param>
	/// <returns>Success</returns>
	double GiiMote::wm_mii_data_inject(System::String^ fName,double miiBlock, double miiNumber)
	{
		cli::array<unsigned char,1>^ miiBuffer;
		int miiNum = (int)miiNumber;
		// Detect invalid arguments
		if (miiNum > 10 || miiNum < 0 || miiBlock < 0 || miiBlock > 2)
		{
			return ( 0 );
		}
		System::IO::FileStream^ miiFile = gcnew System::IO::FileStream(fName,System::IO::FileMode::Open);
		miiBuffer->Resize(miiBuffer,0);
		int miiLoc = (MII_LENGTH*(miiNum-1))*(miiNum!=0);
		int blockStart = MII_DATA_START + (MII_BLOCK_SIZE*(miiBlock==2));
		int start = blockStart + miiLoc;

		// Check to see how many blocks the file contains.
		switch (miiFile->Length)
		{
		case MII_DATA_LENGTH:
			if (miiBlock == 0)
			{
				miiBuffer->Resize(miiBuffer,MII_DATA_LENGTH);
				miiFile->Read(miiBuffer,0,MII_DATA_LENGTH);
			}
			else
			{
				miiFile->Read(miiBuffer,MII_BLOCK_SIZE*(miiBlock >= 2),MII_BLOCK_SIZE);
			}
			break;
		case MII_BLOCK_SIZE:
			miiBuffer->Resize(miiBuffer,MII_BLOCK_SIZE);
			miiFile->Read(miiBuffer,0,MII_BLOCK_SIZE);
			break;
		default:
			miiFile->Close();
			delete miiFile;
			return ( 0 );
			break;
		}

		miiFile->Close();
		delete miiFile;

		// Update the CRC and other info.
		switch (miiBuffer->Length)
		{
		case MII_BLOCK_SIZE:
			miiBuffer = wm_mii_data_update(miiBuffer);
			break;
		case MII_DATA_LENGTH:
			cli::array<unsigned char,1>^ tBuff1 = gcnew cli::array<unsigned char,1>(MII_BLOCK_SIZE);
			cli::array<unsigned char,1>^ tBuff2 = gcnew cli::array<unsigned char,1>(MII_BLOCK_SIZE);
			System::Array::Copy(miiBuffer,0,tBuff1,0,MII_BLOCK_SIZE);
			System::Array::Copy(miiBuffer,MII_BLOCK_SIZE,tBuff2,0,MII_BLOCK_SIZE);

			tBuff1 = wm_mii_data_update(tBuff1);
			tBuff2 = wm_mii_data_update(tBuff2);

			miiBuffer[750] = tBuff1[750];
			miiBuffer[751] = tBuff1[751];
			miiBuffer[1502] = tBuff2[750];
			miiBuffer[1503] = tBuff2[751];
			delete tBuff1;
			delete tBuff2;
			break;
		}

		switch (miiBuffer->Length)
		{
		case MII_BLOCK_SIZE:
			if (miiNum == 0)
			{

				/*for(int c=0;c<MII_BLOCK_SIZE;c++)
				{
					try {
						this->wc[wmIndex]->WriteData(start + c,miiBuffer[c]);
					}
					catch(...) {
						return ( 0 );
					}
				}*/
				try
				{
					this->wc[wmIndex]->WriteData(start, sizeof(unsigned char), miiBuffer);
				}
				catch(...)
				{
					delete miiBuffer;
					return ( 0 );
				}
			}
			else
			{
				// Write the individual Mii from the file.
				/*for(int c=0;c<MII_LENGTH;c++)
				{
					try {
						this->wc[wmIndex]->WriteData(start + c,miiBuffer[((miiNum-1)*MII_LENGTH)+c]);
					}
					catch(...) {
						return ( 0 );
					}
				}*/

				try
				{
					cli::array<unsigned char>^ individualMiiBuffer;
					cli::array<unsigned char>::ConstrainedCopy(miiBuffer, ((miiNum-1)*MII_LENGTH), individualMiiBuffer, 0, MII_LENGTH);
					this->wc[wmIndex]->WriteData(start, sizeof(unsigned char), individualMiiBuffer );
					delete individualMiiBuffer;
				}
				catch(...)
				{
					delete miiBuffer;
					return ( 0 );
				}
				// Update the CRC on the Wii Remote
				try
				{
					this->wc[wmIndex]->WriteData(blockStart+MII_BLOCK_SIZE-2,miiBuffer[MII_BLOCK_SIZE-2]);
					this->wc[wmIndex]->WriteData(blockStart+MII_BLOCK_SIZE-1,miiBuffer[MII_BLOCK_SIZE-1]);
				}
				catch(...)
				{
					delete miiBuffer;
					return ( 0 );
				}
			}
			break;
		case MII_DATA_LENGTH:
			if (miiNum == 0)
			{
				/*for(int c=0;c<MII_DATA_LENGTH;c++)
				{
					try {
						this->wc[wmIndex]->WriteData(MII_DATA_START + c,miiBuffer[c]);
					}
					catch(...) {
						return ( 0 );
					}
				}*/
				try
				{
					this->wc[wmIndex]->WriteData(MII_DATA_START, sizeof(unsigned char), miiBuffer);
				}
				catch(...)
				{
					delete miiBuffer;
					return ( 0 );
				}
			}
			else // Update individual Mii on the Wii Remote
			{
				// unsigned char wChar;
				/*for(int c=0;c<MII_LENGTH;c++)
				{
					wChar = miiBuffer[((miiNum-1)*MII_LENGTH)+c];
					try
					{
						this->wc[wmIndex]->WriteData(MII_DATA_START + miiLoc + c,wChar);
						this->wc[wmIndex]->WriteData(MII_DATA_START + MII_BLOCK_SIZE + miiLoc  + c,wChar);
					}
					catch(...)
					{
						return ( 0 );
					}
				}*/
				cli::array<unsigned char>^ individualMiiBuffer;
				cli::array<unsigned char>::ConstrainedCopy(miiBuffer, ((miiNum-1)*MII_LENGTH), individualMiiBuffer, 0, miiBuffer->Length);
				try
				{
					this->wc[wmIndex]->WriteData(MII_DATA_START + miiLoc, sizeof(unsigned char), individualMiiBuffer);
					this->wc[wmIndex]->WriteData(MII_DATA_START + MII_BLOCK_SIZE + miiLoc, sizeof(unsigned char), individualMiiBuffer);
				}
				catch(...)
				{
					delete individualMiiBuffer;
					delete miiBuffer;
					return ( 0 );
				}
				delete individualMiiBuffer;
				// Update the CRC on the Wii Remote
				// Use two separate try/catch statements so that if the first fails to write
				// for some reason the second may still be written and be valid on the Wii Remote.
				try 
				{
					this->wc[wmIndex]->WriteData(MII_DATA_START+MII_BLOCK_SIZE-2,miiBuffer[MII_BLOCK_SIZE-2]);
					this->wc[wmIndex]->WriteData(MII_DATA_START+MII_BLOCK_SIZE-1,miiBuffer[MII_BLOCK_SIZE-1]);
				}
				catch(...)
				{
					// Do not return, try the next one first.
					// Only one block is needed by the Wii Remote.
				}
				try
				{
					this->wc[wmIndex]->WriteData(blockStart+(2*MII_BLOCK_SIZE)-2,miiBuffer[(2*MII_BLOCK_SIZE)-2]);
					this->wc[wmIndex]->WriteData(blockStart+(2*MII_BLOCK_SIZE)-1,miiBuffer[(2*MII_BLOCK_SIZE)-1]);
				}
				catch(...)
				{
					delete miiBuffer;
					return ( 0 );
				}
			}
			break;
		default:
			delete miiBuffer;
			return ( 0 );
			break;
		}

		delete miiBuffer;
		return ( 1 );
	}

	/// <summary>Updates the CRC checksum of a mii block file</summary>
	/// <param name="fName">The file name</param>
	/// <returns>1</returns>
	double GiiMote::wm_mii_update_crc(System::String^ fName)
	{
		System::IO::FileStream^ miiFile = gcnew System::IO::FileStream(fName,System::IO::FileMode::Open);
		cli::array<unsigned char,1>^ miiBuffer;
		miiBuffer->Resize(miiBuffer,(int)miiFile->Length);
		miiFile->Read(miiBuffer,0,(int)miiFile->Length);

		switch (miiBuffer->Length)
		{
		case MII_BLOCK_SIZE:
			miiBuffer = wm_mii_data_update(miiBuffer);
			miiFile->SetLength(MII_BLOCK_SIZE - 2);
			miiFile->WriteByte(miiBuffer[750]);
			miiFile->WriteByte(miiBuffer[751]);
			break;
		case (MII_BLOCK_SIZE * 2):

			cli::array<unsigned char,1>^ tBuff1;
			cli::array<unsigned char,1>^ tBuff2;
			miiBuffer->ConstrainedCopy(miiBuffer,0,tBuff2,0,MII_BLOCK_SIZE);
			miiBuffer->ConstrainedCopy(miiBuffer,MII_BLOCK_SIZE,tBuff2,0,MII_BLOCK_SIZE);

			tBuff1 = wm_mii_data_update(tBuff1);
			tBuff2 = wm_mii_data_update(tBuff2);

			miiBuffer[750] = tBuff1[750];
			miiBuffer[751] = tBuff1[751];
			miiBuffer[1502] = tBuff2[750];
			miiBuffer[1503] = tBuff2[751];

			miiFile->SetLength(0);
			miiFile->Write(miiBuffer,0,miiBuffer->Length);
			break;
		}

		miiFile->Close();
		delete miiFile;
		return (1);
	}

	/// <summary>Updates the given Mii data</summary>
	/// <param name="miiData">The mii data to update</param>
	/// <returns>Updated mii data</returns>
	cli::array<unsigned char,1>^ GiiMote::wm_mii_data_update(cli::array<unsigned char,1>^ miiData)
	{
		cli::array<unsigned char,1>^ text = miiData;
		unsigned short st = 0x0000;
		unsigned short good_crc = st;
		unsigned short bad_crc = st;
		unsigned short text_length = 750;
		int off = 0;

		// go
		// unsigned short ch;
		unsigned short i, v, xor_flag;

		for(int j=0; j<(text_length-off); j++) {
			//update_good_crc(text[j+off]);
			// update-good-crc
	    
		// Align test bit with leftmost bit of the message byte.
	    
		v = 0x80;

		for (i=0; i<8; i++)
		{
			if (good_crc & 0x8000)
			{
				xor_flag= 1;
			}
			else
			{
				xor_flag= 0;
			}
			good_crc = good_crc << 1;

			if (text[j+off] & v)
			{

				//Append next bit of message to end of CRC if it is not zero.
				//The zero bit placed there by the shift above need not be
				//changed if the next bit of the message is zero.
	       
				good_crc= good_crc + 1;
			}

			if (xor_flag)
			{
				good_crc = good_crc ^ poly;
			}


			// Align test bit with next bit of the message byte.
			v = v >> 1;
		}
			// update-good-crc-end
		}
		// augment_message_for_good_crc();
		for (i=0; i<16; i++)
		{
			if (good_crc & 0x8000)
			{
				xor_flag= 1;
			}
			else
			{
				xor_flag= 0;
			}
			good_crc = good_crc << 1;

			if (xor_flag)
			{
				good_crc = good_crc ^ poly;
			}
		}
		// augment-message-for-good-crc-end
		// end-go

		text[750] = (good_crc&0xFF00)>>8;
		text[751] = (good_crc&0x00FF);
		
		return (text);
	}

} // Namespace GiiMoteLib
