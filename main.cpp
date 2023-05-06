#include <iostream>
#include <string.h>

typedef struct Contacto{
    char nombre[10];
    char direccion[30];
    char telefono[12];
}Contacto;

Contacto instanciarContacto(){
    Contacto contacto;
    return contacto;
}

void setNombre(Contacto *contacto, char nombre[]){
    strcpy(contacto->nombre,nombre);
}

void setDireccion(Contacto *contacto, char direccion[]){
    strcpy(contacto->direccion,direccion);
}

void setTelefono(Contacto *contacto,char telefono[]){
    strcpy(contacto->telefono,telefono);
}

void mostrarDatos(Contacto *contacto){
    printf("Nombre: %s\nDireccion: %s\nTelefono: %s\n-----\n",contacto->nombre,contacto->direccion,contacto->telefono);
}

typedef struct Agenda{
    Contacto constactos[3];
    int contador;
}Agenda;

Agenda instanciarAgenda(){
    Agenda agenda;
    agenda.contador = 0;
    return agenda;
}

void inicializarAgenda(Agenda *agenda){
    for(int i=0;i<sizeof(agenda->constactos)/sizeof(Contacto);i++){
        Contacto c = {"VACIO","VACIO","VACIO"};
        agenda->constactos[i] = c;
    }
}

void agregarContacto(Agenda *agenda,Contacto contacto){
    agenda->constactos[agenda->contador] = contacto;
    agenda->contador++;
}

void mostrarDatosContactos(Agenda *agenda){
    for(int i=0;i<sizeof(agenda->constactos)/sizeof(Contacto);i++){
        Contacto c = agenda->constactos[i];
        mostrarDatos(&c);
    }
}

int main() {
    Agenda agenda = instanciarAgenda();
    inicializarAgenda(&agenda);

    Contacto c1 = instanciarContacto();
    setNombre(&c1,"Emanuel");
    setDireccion(&c1,"AV San Martin 2131");
    setTelefono(&c1,"01171602740");
    agregarContacto(&agenda,c1);

    Contacto c2 = instanciarContacto();
    setNombre(&c2,"Ana");
    setDireccion(&c2,"Juan Jose Silva 590");
    setTelefono(&c2,"3704741289");
    agregarContacto(&agenda,c2);

    Contacto c3 = instanciarContacto();
    setNombre(&c3,"Carmen");
    setDireccion(&c3,"Juan Jose Silva 1352");
    setTelefono(&c3,"3704715993");
    agregarContacto(&agenda,c3);

    mostrarDatosContactos(&agenda);
    return 0;
}
