#ifndef CLIENTVIEW_H_
#define CLIENTVIEW_H_

#include <gtkmm/window.h>
#include <gtkmm/textview.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/paned.h>
#include <gtkmm/scrolledwindow.h>

class ClientView : public Gtk::Window {
  private:
    // Widgets
    Gtk::HPaned hLayout;
    Gtk::VPaned vLayout;
    Gtk::ScrolledWindow scrolledWindow;    
    Gtk::TextView chatTextView;
    Gtk::Entry msgEntry;    
    Gtk::Button sendButton;
    
    // Inicializacion de Timers.
    void initTimers();
    
    // Inicializacion Visual.
    void initWidgets();
    void buildLayout();
    
    // Manejo de signals.
    void onSendButtonClicked();
    void onEnterPressed();
    

    /**
     * Procesa el contenido de msgEntry.
     */
    void processEntryText();
    /**
     * Crea un nuevo Cliente IRC, conectandose a un servidor cuyos datos se 
     * reciben como parametro. En caso de que ya estemos conectados a un 
     * servidor, se efectuara una desconexion del mismo y se re conectara al 
     * nuevo servidor parametrizado.
     */
    void createIrcClient(const Glib::ustring& params);
    /**
     * Escribe el texto pasado como parametro en el chatTextView.
     */
    void writeToChatTextView(const Glib::ustring& text);    
    /**
     * Detiene el chequeo de mensajes entrantes.
     * Desconecta y deja en null al cliente IRC.
     */
    void resetIrcClient(); 
    /**
     * Chequea si hay mensajes entrantes para mostrar.
     */
    bool checkForIncomingMessages();
     
  public:
    ClientView();
    virtual ~ClientView();          
};

#endif /*CLIENTVIEW_H_*/
