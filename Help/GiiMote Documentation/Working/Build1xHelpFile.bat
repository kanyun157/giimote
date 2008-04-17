@ECHO OFF

REM Step 6 - Build the HTML 1.x help file
cd .\Output
copy ..\*.hhp . > NUL
copy ..\*.hhc . > NUL
copy ..\*.hhk . > NUL

"C:\Program Files\HTML Help Workshop\hhc.exe" Help1x.hhp

cd ..

IF EXIST "C:\Documents and Settings\Leif902\My Documents\Visual Studio 2008\Projects\GiiMote\Help\GiiMote Documentation\Documentation.chm" DEL "C:\Documents and Settings\Leif902\My Documents\Visual Studio 2008\Projects\GiiMote\Help\GiiMote Documentation\Documentation.chm" > NUL
IF EXIST ".\Output\Documentation.chm" COPY ".\Output\Documentation.chm" "C:\Documents and Settings\Leif902\My Documents\Visual Studio 2008\Projects\GiiMote\Help\GiiMote Documentation\" > NUL

REM Must remove these in case we are building a 2x file or website as well
del .\Output\*.hhp > NUL
del .\Output\*.hhc > NUL
del .\Output\*.hhk > NUL
del ".\Output\Documentation.chm" > NUL
del ".\Output\Documentation.log" > NUL
