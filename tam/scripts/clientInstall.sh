#! /bin/bash

echo -n "Ingrese el Directorio en donde desea instalar el Cliente de TAM: "
read installDir

mkdir -p "${installDir}"
mkdir -p "${installDir}/tmp"
mkdir -p "${installDir}/view"
cp "bin/tamClient" "${installDir}"
cp "view/dlgInitWindow.glade" "${installDir}/view"
cp "view/gameWindow.glade" "${installDir}/view"
cp "view/feedbackWindow.glade" "${installDir}/view"
