@ECHO OFF

REM Step 4.2 - Generate a table of content for an HTML 1.x help file
"C:\Program Files\Sandcastle\ProductionTools\XslTransform" /xsl:"C:\Program Files\Sandcastle\ProductionTransforms\TocToChmContents.xsl" toc.xml /out:"Documentation.hhc"
