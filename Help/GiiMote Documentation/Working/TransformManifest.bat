@ECHO OFF

REM Step 2 - Transform the reflection output
if {%1} == {vs2005} (
"C:\Program Files\Sandcastle\ProductionTools\XslTransform" /xsl:"C:\Program Files\Sandcastle\ProductionTransforms\ApplyVSDocModel.xsl","C:\Program Files\Sandcastle\ProductionTransforms\AddGuidFilenames.xsl" reflection.org /out:reflection.xml /arg:IncludeAllMembersTopic=true /arg:IncludeInheritedOverloadTopics=true 
) else if {%1} == {hana} (
"C:\Program Files\Sandcastle\ProductionTools\XslTransform" /xsl:"C:\Program Files\Sandcastle\ProductionTransforms\ApplyVSDocModel.xsl","C:\Program Files\Sandcastle\ProductionTransforms\AddGuidFilenames.xsl" reflection.org /out:reflection.xml /arg:IncludeAllMembersTopic=false /arg:IncludeInheritedOverloadTopics=true 
) else (
"C:\Program Files\Sandcastle\ProductionTools\XslTransform" /xsl:"C:\Program Files\Sandcastle\ProductionTransforms\ApplyPrototypeDocModel.xsl","C:\Program Files\Sandcastle\ProductionTransforms\AddGuidFilenames.xsl" reflection.org /out:reflection.xml
)

REM Generate a topic manifest
"C:\Program Files\Sandcastle\ProductionTools\XslTransform" /xsl:"C:\Program Files\Sandcastle\ProductionTransforms\ReflectionToManifest.xsl" reflection.xml /out:manifest.xml
