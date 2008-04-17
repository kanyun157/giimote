@ECHO OFF

REM Step 5 - Generate an index for an HTML 1.x help file
"C:\Program Files\Sandcastle\ProductionTools\XslTransform" /xsl:"C:\Program Files\Sandcastle\ProductionTransforms\ReflectionToChmIndex.xsl" reflection.xml /out:"Documentation.hhk"
