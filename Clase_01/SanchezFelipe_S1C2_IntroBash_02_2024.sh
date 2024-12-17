#!/bin/bash

mkdir herramientas_computacionales
cd herramientas_computacionales
touch loquesea.tex
cp loquesea.tex loquesea2.tex
ls
mv loquesea2.tex loquesea3.tex
rm loquesea3.tex
cd ..
cp -r herramientas_computacionales herramientas_computacionales2
rm -r herramientas_computacionales
