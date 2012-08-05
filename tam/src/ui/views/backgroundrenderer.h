#ifndef __UI__VIEWS__BACKGROUNDRENDERER_H_INCLUDED__
#define __UI__VIEWS__BACKGROUNDRENDERER_H_INCLUDED__

#include "renderer.h"
#include <string>

namespace ui {
	namespace views {
		/**
		 * Implementacion de Renderer que dibuja
		 * una imagen de fondo
		 */
		class BackgroundRenderer : public Renderer {
			private:
				Glib::RefPtr<Gdk::Pixbuf> pixBuf;
				Cairo::RefPtr<Cairo::ImageSurface> imageSurface;

			public:
				/**
				 * Crea una nueva instancia de BackgroundRenderer
				 * @param filename Nombre del archivo de imagen
				 * utilizado para dibujar el fondo
				 */
				BackgroundRenderer(const std::string& filename);

				/**
				 * @see Renderer#render
				 */
				virtual void render(Cairo::RefPtr<Cairo::Context> drawingContext) const;
		};
	}
}

#endif /*__UI__VIEWS__BACKGROUNDRENDERER_H_INCLUDED__*/
