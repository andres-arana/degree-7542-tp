#include "clientview.h"

#define WINDOW_TITLE "FIUBA Chat Client"
#define BORDER_WIDTH 5
#define WINDOW_SIZE 400, 400
#define VLAYOUT_POS 350
#define HLAYOUT_POS 300
#define CHAT_TEXTVIEW_SIZE 400, 375
#define MSG_ENTRY_SIZE 325, 25
#define SEND_BUTTON_SIZE 75, 25

using namespace std;

ClientView::ClientView() {
  this->initWidgets();
  this->buildLayout();
  show_all_children();
}

ClientView::~ClientView() {

}

void ClientView::initWidgets() {
  // Titulo de la Ventana.
  set_title(WINDOW_TITLE);
  // Ancho del Borde.
  set_border_width(BORDER_WIDTH);
  // Tamanio por defecto.
  set_default_size(WINDOW_SIZE);
  // Atributos del Vertical Layout.
  this->vLayout.set_position(VLAYOUT_POS);
  // Atributos del Horizontal Layout.
  this->hLayout.set_position(HLAYOUT_POS);
  // Atributos de la Scrolled Windows.
  this->scrolledWindow.set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);
  // Atributos del chatTextView
  this->chatTextView.set_size_request(CHAT_TEXTVIEW_SIZE);
  this->chatTextView.set_editable(false);
  this->chatTextView.set_resize_mode(Gtk::RESIZE_IMMEDIATE);
  this->chatTextView.set_wrap_mode(Gtk::WRAP_WORD_CHAR);
  // Atributos del msgTextView
  this->msgEntry.set_size_request(MSG_ENTRY_SIZE);
  this->msgEntry.signal_activate()
      .connect(sigc::mem_fun(*this, &ClientView::onEnterPressed));
  // Atributos del Boton.
  this->sendButton.set_size_request(SEND_BUTTON_SIZE);
  this->sendButton.set_label("Send");
  this->sendButton.signal_clicked()
      .connect(sigc::mem_fun(*this, &ClientView::onSendButtonClicked));
     
}

void ClientView::buildLayout() {
  // Layout de controles.   
  add(vLayout);
  this->scrolledWindow.add(this->chatTextView);
  this->vLayout.pack1(this->scrolledWindow);
  this->vLayout.pack2(this->hLayout);
  this->hLayout.pack1(this->msgEntry);
  this->hLayout.pack2(this->sendButton);
  this->msgEntry.grab_focus();  
}

void ClientView::onSendButtonClicked() {
  this->processEntryText();
  this->msgEntry.grab_focus();
}

void ClientView::onEnterPressed() {
  this->processEntryText();
}

void ClientView::processEntryText() {
  Glib::ustring entryText = this->msgEntry.get_text();
  if (entryText.empty()) return;

	entryText.append("\n");
	this->writeToChatTextView(entryText);
  this->msgEntry.set_text("");
}

void ClientView::writeToChatTextView(const Glib::ustring& text) {
  Glib::RefPtr<Gtk::TextBuffer> buffer = this->chatTextView.get_buffer();
  buffer->insert(buffer->end(), text);
  // "Scrolleo" a la ultima linea.
  this->chatTextView.scroll_to(buffer->create_mark(buffer->end()));
}
