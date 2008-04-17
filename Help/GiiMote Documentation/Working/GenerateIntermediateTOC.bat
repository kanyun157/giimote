@ECHO OFF

REM Step 4 - Generate an intermediate table of content file
if {%1} == {prototype} (
"C:\Program Files\Sandcastle\ProductionTools\XslTransform" /xsl:"C:\Program Files\Sandcastle\ProductionTransforms\CreatePrototypeToc.xsl" reflection.xml /out:toc.xml
) else (
"C:\Program Files\Sandcastle\ProductionTools\XslTransform" /xsl:"C:\Program Files\Sandcastle\ProductionTransforms\CreateVSToc.xsl" reflection.xml /out:toc.xml
)
