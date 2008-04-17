@ECHO OFF

REM Step 1 - Generate the reflection information
"C:\Program Files\Sandcastle\ProductionTools\MRefBuilder" /config:MRefBuilder.config /out:reflection.org /dep:DLL\*.*  *.dll *.exe
