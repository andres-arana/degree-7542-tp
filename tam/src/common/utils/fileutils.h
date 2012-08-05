#ifndef FILEUTILS_H_
#define FILEUTILS_H_

#include <string>

namespace common {
	namespace utils {
		/**
		 * Clase utilitaria para le manejo de Archivos.
		 * @author Gabriel Raineri
		 */
		class FileUtils {
			private:
				// No instanciable.
				FileUtils();
				~FileUtils();
				// No copiable.
				FileUtils(const FileUtils &fu);
				// No asignable.
				FileUtils& operator=(const FileUtils &fu);
				 			
			public:
				/**
				 * Retorna la longitud de un archivo dado su direccion.
				 * @return La longitud del archivo.
				 */
				static long getFileSize(const std::string& path);
				/**
				 * Retorna si un archivo o directorio existe o no.
				 * @return Verdadero si el archivo o directorio existe. Sino, falso.
				 */
				static bool fileExists(const std::string& path);
				/**
				 * Cuenta la cantidad de archivos o directorios dentro de un directorio
				 * base.
				 * @param basePath El directorio base a partir del cual buscar.
				 * @param excludeDotDirs Excluye los directorios "." y "..".
				 */
				static int countDirs(std::string& basePath, bool excludeDotDirs);
				/**
 				 * Copia un archivo.
				 * @param src Ruta y nombre del archivo de origen.
				 * @param dst Ruta y nombre del archivo de destino.
				 */
				static void copy(const std::string& src, const std::string& dst);				
		};
	}
}
#endif /*FILEUTILS_H_*/
