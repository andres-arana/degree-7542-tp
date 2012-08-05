#ifndef __UI__VIEWS__GAMERENDERAREA_H_INCLUDED__
#define __UI__VIEWS__GAMERENDERAREA_H_INCLUDED__

#include "renderer.h"
#include <gtkmm.h>

namespace ui {
	namespace views {
		/**
		 * Widget de GTK de dibujo personalizado. Utiliza renderers
		 * para dibujar en su superficie. Un renderer es un objeto
		 * encargado de dibujar sobre una superfice de cairo. El
		 * GameRenderArea agrupa renderers relacionados en distintas
		 * capas, y permite habilitar o deshabilitar las distintas
		 * capas. Expone ademas un conjunto de señales basicas
		 * para la interaccion con el usuario.
		 */
		class GameRenderArea : public Gtk::DrawingArea {
		public:
			enum RenderLayers {
				BackgroundLayer = 0,
				ElementDesignLayer,
				ElementRuntimeLayer,
				MovePointLayer,
				ConnectPointLayer,
				OverlayLayer
			};

			/**
			 * Crea una nueva instancia de GameRenderArea
			 * @param scale Parametro de escalamiento para
			 * las coordenadas de dibujo
			 */
			GameRenderArea(double scale = 1.0);

			/**
			 * Añade un renderer a un layer especificado.
			 * El lifecycle del renderer agregado pasa a ser
			 * responsabilidad del GameRenderArea.
			 * @param layer Grupo al que pertenecera el renderer
			 * @param renderer Renderer a agregar
			 */
			void addRendererToLayer(RenderLayers layer, Renderer *renderer);

			/**
			 * Habilita un grupo de renderers para ser dibujados.
			 * Estos serar dibujados la proxima vez que se llame
			 * al metodo GameRenderArea#redraw.
			 * @param layer Grupo de renderers a habilitar.
			 */
			void enableLayer(RenderLayers layer);

			/**
			 * Deshabilita un grupo de renderers para ser dibujados.
			 * Estos no seran dibujados la proxima vez que se llame
			 * al metodo GameRenderArea#redraw.
			 * @param layer Grupo de renderers a habilitar.
			 */
			void disableLayer(RenderLayers layer);

			/**
			 * Almacena una copia del estado de las habilitaciones
			 * de los distintos grupos de renderers para poder ser
			 * restaurada posteriormente
			 */
			void saveLayersState();

			/**
			 * Restaura el estado de las habilitaciones de los
			 * distintos grupos de renderers grabados anteriormente
			 * a traves de GameRenderArea#saveLayersState
			 */
			void restoreLayersState();

			/**
			 * Establece la configuracion de Renderers por defecto para
			 * el modo de ejecucion, habilitando solamente las capas
			 * de Runtime y Background
			 */
			void swapToRuntimeMode();

			/**
			 * Invalida el area del GameRenderArea, lo que schedulea
			 * en la cola de eventos de GTK una peticion de redibujado
			 */
			void redraw();

			typedef sigc::signal<void, int, int> mouse_pressed_signal_type;
			/**
			 * Señal emitida cuando se presiona el mouse sobre
			 * el GameRenderArea
			 */
			mouse_pressed_signal_type &signalMousePressed();

			typedef sigc::signal<void, int, int> mouse_released_signal_type;
			/**
			 * Señal emitida cuando se suelta el mouse sobre
			 * el GameRenderArea
			 */
			mouse_released_signal_type &signalMouseReleased();

			typedef sigc::signal<void, int, int> mouse_motion_signal_type;
			/**
			 * Señal emitida cuando se mueve el mouse sobre
			 * el GameRenderArea
			 */
			mouse_motion_signal_type &signalMouseMotion();

			/**
			 * Elimina todos los renderers del GameRenderArea
			 */
			void disposeRenderers();

			~GameRenderArea();
		protected:
			virtual bool on_expose_event(GdkEventExpose* event);

			virtual bool on_button_press_event(GdkEventButton* event);

			virtual bool on_button_release_event(GdkEventButton* event);

			virtual bool on_motion_notify_event(GdkEventMotion* event);

		private:
			typedef std::vector<Renderer *> renderer_pointer_list;
			typedef std::vector<renderer_pointer_list> layer_list;
			typedef std::vector<bool> enabled_list;

			layer_list layers;
			enabled_list enabledLayers;
			enabled_list enabledLayersBackup;

			double scale;

			int scaleCoordinate(int coord) const;

			mouse_pressed_signal_type mousePressedSignal;
			mouse_released_signal_type mouseReleasedSignal;
			mouse_motion_signal_type mouseMotionSignal;

			void setDefaultCursorType();
			void setDragCursorType();
		};
	}
}

#endif
