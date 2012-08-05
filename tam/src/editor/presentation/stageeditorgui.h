#ifndef EDITOR_PRESENTATION_STAGEEDITORGUI_H_
#define EDITOR_PRESENTATION_STAGEEDITORGUI_H_

#include <string>

namespace editor {namespace presentation {
	/**
	 * Esta interface es implementada por la ventana principal del editor de
	 * escenarios.
	 * @version 1.0
	 * @created 23-Oct-2008 04:36:29 a.m.
	 */
	class StageEditorGui {
	public:
		/** Muestra el nombre del escenario */
		virtual void showStageName(const std::string& name) =0;
		/** @return El tiempo maximo ingresado */
		virtual unsigned getMaxTime() =0;
		/** Asigna el tiempo maximo */
		virtual void setMaxTime(unsigned maxTime) =0;
		/** @return El nombre de la imagen seleccionada como fondo de escenario */
		virtual std::string getBackground() =0;
		/** Asigna el nombre de la imagen de fondo del escenario */
		virtual void setBackground(const std::string& background) =0;
		/** @return La gravedad ingresada */
		virtual int getGravity() =0;
		/** Asigna la gravedad */
		virtual void setGravity(int gravity) =0;
		/** @return El valor ingresado para la constante A */
		virtual int getA() =0;
		/** Asigna el valor para la constante A */
		virtual void setA(int a) =0;
		/** @return El valor ingresado para la constante B */
		virtual int getB() =0;
		/** Asigna el valor para la constante B */
		virtual void setB(int b) =0;
		/** @return El valor ingresado para la constante C */
		virtual int getC() =0;
		/** Asigna el valor para la constante C */
		virtual void setC(int c) =0;
		/** @return El valor ingresado para la constante D */
		virtual int getD() =0;
		/** Asigna el valor para la constante D */
		virtual void setD(int d) =0;
		/** Asigna la cantidad de barras metalicas */
		virtual void setMetalBarCount(unsigned u) =0;
		/* @return La cantidad de barras metalicas */
		virtual unsigned getMetalBarCount() =0;
		/** Asigna el precio de las barras metalicas */
		virtual void setMetalBarPrice(unsigned u) =0;
		/* @return El precio de las barras metalicas */
		virtual unsigned getMetalBarPrice() =0;
		/** Asigna la longitud minima de las barras metalicas */
		virtual void setMetalBarMinSize(unsigned u) =0;
		/* @return La longitud minima de las barras metalicas */
		virtual unsigned getMetalBarMinSize() =0;
		/** Asigna la longitud maxima de las barras metalicas */
		virtual void setMetalBarMaxSize(unsigned u) =0;
		/* @return La longitud maxima de las barras metalicas */
		virtual unsigned getMetalBarMaxSize() =0;
		/** Asigna la cantidad de plataformas */
		virtual void setPlataformCount(unsigned u) =0;
		/* @return La cantidad de plataformas */
		virtual unsigned getPlataformCount() =0;
		/** Asigna el precio de las plataformas */
		virtual void setPlataformPrice(unsigned u) =0;
		/* @return El precio de las plataformas */
		virtual unsigned getPlataformPrice() =0;
		/** Asigna la longitud minima de las plataformas */
		virtual void setPlataformMinSize(unsigned u) =0;
		/* @return La longitud minima de las plataformas */
		virtual unsigned getPlataformMinSize() =0;
		/** Asigna la longitud maxima de las plataformas */
		virtual void setPlataformMaxSize(unsigned u) =0;
		/* @return La longitud maxima de las plataformas */
		virtual unsigned getPlataformMaxSize() =0;
		/** Asigna la cantidad de sogas */
		virtual void setRopeCount(unsigned u) =0;
		/* @return La cantidad de sogas */
		virtual unsigned getRopeCount() =0;
		/** Asigna el precio de las sogas */
		virtual void setRopePrice(unsigned u) =0;
		/* @return El precio de las sogas */
		virtual unsigned getRopePrice() =0;
		/** Asigna la longitud minima de las sogas */
		virtual void setRopeMinSize(unsigned u) =0;
		/* @return La longitud minima de las sogas */
		virtual unsigned getRopeMinSize() =0;
		/** Asigna la longitud maxima de las sogas */
		virtual void setRopeMaxSize(unsigned u) =0;
		/* @return La longitud maxima de las sogas */
		virtual unsigned getRopeMaxSize() =0;
		/** Asigna la cantidad de cintas de lona */
		virtual void setCanvasTapeCount(unsigned u) =0;
		/* @return La cantidad de cintas de lona */
		virtual unsigned getCanvasTapeCount() =0;
		/** Asigna el precio de las cintas de lona */
		virtual void setCanvasTapePrice(unsigned u) =0;
		/* @return El precio de las cintas de lona */
		virtual unsigned getCanvasTapePrice() =0;
		/** Asigna la longitud minima de las cintas de lona */
		virtual void setCanvasTapeMinSize(unsigned u) =0;
		/* @return La longitud minima de las cintas de lona */
		virtual unsigned getCanvasTapeMinSize() =0;
		/** Asigna la longitud maxima de las cintas de lona */
		virtual void setCanvasTapeMaxSize(unsigned u) =0;
		/* @return La longitud maxima de las cintas de lona */
		virtual unsigned getCanvasTapeMaxSize() =0;
		/** Asigna la cantidad de ruedas */
		virtual void setWheelCount(unsigned u) =0;
		/* @return La cantidad de ruedas */
		virtual unsigned getWheelCount() =0;
		/** Asigna el precio de las ruedas */
		virtual void setWheelPrice(unsigned u) =0;
		/* @return El precio de las ruedas */
		virtual unsigned getWheelPrice() =0;
		/** Asigna la longitud minima de las ruedas */
		virtual void setWheelMinSize(unsigned u) =0;
		/* @return La longitud minima de las ruedas */
		virtual unsigned getWheelMinSize() =0;
		/** Asigna la longitud maxima de las ruedas */
		virtual void setWheelMaxSize(unsigned u) =0;
		/* @return La longitud maxima de las ruedas */
		virtual unsigned getWheelMaxSize() =0;
		/** Asigna el torque de las ruedas */
		virtual void setWheelTorke(unsigned u) =0;
		/* @return El torque de las ruedas */
		virtual unsigned getWheelTorke() =0;
		/** Asigna el tiempo de accion de las ruedas */
		virtual void setWheelDecayTime(unsigned u) =0;
		/* @return El tiempo de accion de las ruedas */
		virtual unsigned getWheelDecayTime() =0;
		/** Asigna la cantidad de masas */
		virtual void setMassCount(unsigned u) =0;
		/* @return La cantidad de masas */
		virtual unsigned getMassCount() =0;
		/** Asigna el precio de las masas */
		virtual void setMassPrice(unsigned u) =0;
		/* @return El precio de las masas */
		virtual unsigned getMassPrice() =0;
		/** Asigna la masa */
		virtual void setMass(unsigned u) =0;
		/* @return La masa */
		virtual unsigned getMass() =0;
		/** Asigna la longitud minima de las masas */
		virtual void setMassMinSize(unsigned u) =0;
		/* @return La longitud minima de las masas */
		virtual unsigned getMassMinSize() =0;
		/** Asigna la longitud maxima de las masas */
		virtual void setMassMaxSize(unsigned u) =0;
		/* @return La longitud maxima de las masas */
		virtual unsigned getMassMaxSize() =0;
		/** Asigna la cantidad de cohetes */
		virtual void setRocketCount(unsigned u) =0;
		/* @return La cantidad de cohetes */
		virtual unsigned getRocketCount() =0;
		/** Asigna el precio de los cohetes */
		virtual void setRocketPrice(unsigned u) =0;
		/* @return El precio de los cohetes */
		virtual unsigned getRocketPrice() =0;
		/** Asigna la fuerza de los cohetes */
		virtual void setRocketStrength(unsigned u) =0;
		/* @return La fuerza de los cohetes */
		virtual unsigned getRocketStrength() =0;
		/** Asigna el tiempo de accion de los cohetes */
		virtual void setRocketDecayTime(unsigned u) =0;
		/* @return El tiempo de accion de los cohetes */
		virtual unsigned getRocketDecayTime() =0;
		/** Asigna la cantidad de puntos fijos */
		virtual void setFixedPointCount(unsigned u) =0;
		/* @return La cantidad de puntos fijos */
		virtual unsigned getFixedPointCount() =0;
		/** Asigna el precio de los puntos fijos */
		virtual void setFixedPointPrice(unsigned u) =0;
		/* @return El precio de los puntos fijos */
		virtual unsigned getFixedPointPrice() =0;
		/** Asigna la longitud minima de los puntos fijos */
		virtual void setFixedPointMinSize(unsigned u) =0;
		/* @return La longitud minima de los puntos fijos */
		virtual unsigned getFixedPointMinSize() =0;
		/** Asigna la longitud maxima de los puntos fijos */
		virtual void setFixedPointMaxSize(unsigned u) =0;
		/* @return La longitud maxima de los puntos fijos */
		virtual unsigned getFixedPointMaxSize() =0;
		/** Muestra un mensaje de error por pantalla */
		virtual void showMessageError(const std::string& message) =0;
		/**
		 * Muestra una ventana para seleccionar una carpeta
		 * @param folder Carpeta seleccionada
		 * @param saveMode true si se quiere usar el dialogo para grabar, false si se quiere usar el dialogo para cargar.
		 * @return true si se selecciono una carpeta y false si se cerro la ventana sin seleccionar
		 */
		virtual bool showFolderChooserDialog(std::string& folder, bool saveMode) =0;
		/** Elimina de la pantalla los datos del escenario */
		virtual void clear() =0;
		/**
		 * Valida los valores ingresados en todos los campos.
		 * @return true si se paso la validacion y false en otro caso
		 */
		virtual bool validate() =0;

		virtual ~StageEditorGui() {};
	};
}}
#endif // EDITOR_PRESENTATION_STAGEEDITORGUI_H_

