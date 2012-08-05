# Agregamos un ejecutable llamado 'editor' y especificamos sus fuentes.
# Cada vez que se agregue uno, debera agregarse aqui tambien.
add_executable (tamEditor
	main.cpp
	presentation/stageeditorguiglade.cpp
	presentation/stageeditorhandler.cpp
)

execute_process(
	COMMAND ${CMAKE_COMMAND} -E copy
		${TAM_SOURCE_DIR}/src/editor/presentation/editor.glade
		${EXECUTABLE_OUTPUT_PATH}/view/editor.glade
	)

# Linkeamos el ejecutable con las librerias correspondientes.
target_link_libraries (
	tamEditor 
	ui 
	game 
	common 
	${GTKMM_LIBRARIES} 
	${CAIROMM_LIBRARIES} 
	${SIGCMM_LIBRARIES}
	${LIBGLADEMM_LIBRARIES})
