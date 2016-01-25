# Introduction #

This document gives a general outline and overview of the coding styles used in GiiMote.

Before sending in a patch or piece of code for review please refer to this document and make sure your code complies with the recommendations set forth herein.


# General Practices #
  * Make sure your code does not throw warnings or errors.
  * Ensure compatibility with 64-bit hardware.
  * Use "interCaps" for symbols.
  * Use "const" when defining constants
> > for example:
```
        #define btnPlus 8      // This is wrong
        const int btnPlus = 8; // This is right
```
  * Do not create null pointers.
  * Always include a return statement even in functions which do not return data.
> > for example:
```
        void saveA(int a*)
	   {
		a* = 1 + 1;
		return;
	   }
```

# Pointers #
  * Cleanup the heap after yourself when declaring objects.

# Aesthetics #
  * Use proper .NET syntax (new style).
  * Use attributes instead of methods when possible.
  * Use "interCaps" for constants, for example:
```
        const int errorNoIR = -100;
```
  * No white space at the end of a line
  * Use the Allman indent style for control structures. For example:
```
if (...)
{
     (...)
}
else
{
     (...)
}

while (...)
{
     (...)
}

do
{
     (...)
} while (...);

for (...; ...; ...)
{
     (...)
}

switch (...)
{
  case 1:
  {
      // When you need to declare a variable in a switch, put the block in braces
      int var;
  }
  break;
  case 2:
       (...)
       break;
  default:
    break;
}
```
  * Declare methods outside of classes when classes become large.

# Error Handling #
  * Place try-catch statements around everything which interfaces directly with the hardware or can return an error.
  * Do not let errors break the logical progression of your code. Add error checking as a separate entity in the code, do not incorporate it into logic. For example:
```
        // Do not do this:
        if (noError(foobar) && foobar.boolean)
        {
           foobar.setBoolean(false);
        }

        // Do this:
        if (isError(foobar)) return (foobar.lastError());
        if (foobar.boolean)
        {
          foobar.setBoolean(false);
        }
```


| Adapted from the "Mozilla Coding Style Guide" |
|:----------------------------------------------|