#! /bin/bash

echo -n "Ingrese el Directorio en donde desea instalar el Servidor de TAM: "
read installDir

mkdir -p "${installDir}"
mkdir -p "${installDir}/levels"
mkdir -p "${installDir}/view"
cp "bin/tamServer" "${installDir}"
cp "bin/tamEditor" "${installDir}"
cp "view/editor.glade" "${installDir}/view"
cp -r "levels" "${installDir}"
