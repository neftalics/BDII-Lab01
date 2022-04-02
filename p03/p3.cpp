#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

struct Alumno
{
    string Nombre;
    string Apellidos;
    string Carrera;
    float mensualidad;

};

class VariableRecord
{
private:
    string file_name;
public:
    VariableRecord(string name){
        file_name=name;
    }

    void load();
    void add(Alumno alumno);
    Alumno readRecord(int pos);
};

Alumno VariableRecord::readRecord(int pos){
    ifstream file(file_name);
    Alumno alumno;
    int aux = 0;
    string registro;
    while(getline(file,registro) && !file.eof()){
        ++aux;
        stringstream  separator(registro);
        string campo;
        if(aux == pos) {
            aux=0;
            while(getline(separator,campo,'|')){
                switch(aux) 
                {
                    case 0:
                    alumno.Nombre = campo;
                    aux++;
                    break;
                    case 1:
                    alumno.Apellidos = campo;
                    aux++;
                    break;
                    case 2:
                    alumno.Carrera = campo;
                    aux++;
                    default: 
                    alumno.mensualidad = atof(campo.c_str());
                }
                  
            }
            break;
        }
    }
    file.close();
    return alumno;   
}

 


void VariableRecord::add(Alumno alumno){
    ofstream archivo(file_name, ios::app | ios::binary);
    string temp;
    archivo << alumno.Nombre;
    archivo << '|';
    archivo << alumno.Apellidos;
    archivo << '|';
    archivo << alumno.Carrera;
    archivo << '|';
    archivo << alumno.mensualidad;
    archivo <<'\n';
    archivo.close();
}


void VariableRecord::load(){
    vector<Alumno> alumnos;
    ifstream file(file_name);
    string registro;
    int aux;
    
    while(getline(file,registro) && !file.eof()){
        string temporal;
        stringstream  separator(registro);
        aux=0;
        Alumno alumno;
        while(getline(separator,temporal,'|')){
            //
            switch(aux) 
            {
                case 0: 
                alumno.Nombre=temporal;
                ++aux;
                break;
                case 1:
                alumno.Apellidos=temporal;
                ++aux;
                break;
                case 2:
                alumno.Carrera=temporal;
                ++aux;
                break;
                default:
                alumno.mensualidad= atof(temporal.c_str());
                cout<<alumno.Nombre<<" "<<alumno.Apellidos<<" "<<alumno.Carrera<<" "<<alumno.mensualidad<<endl;
                //alumno.mensualidad= stof(temporal);
                //cout<<typeid(alumno.Nombre).name()<<" "<<typeid(alumno.Apellidos).name()<<" "<<typeid(alumno.Carrera).name()<<" "<<typeid(alumno.mensualidad).name()<<endl;
                //alumnos.push_back(alumno);
            }
        }
    }
    file.close();

    //return alumnos;
    
    
}

int main(){
    
    VariableRecord ejemplo("datos2.txt");
    
    cout<<"Se agregara un alumno con las siguientes caracteristicas\n";
    cout<<"Nombre: Eros\nApellidos: Carhuancho Espejo\nCarrera: CS\nMesualidad: 1878.543\n";
    Alumno alumno={"Eros","Carhuancho Espejo","CS",1878.543};
    ejemplo.add(alumno);
    cout<<"El alumno de la posicion 3 es:\n";
    Alumno a= ejemplo.readRecord(3);
    cout<<a.Nombre<<" "<<a.Apellidos<<" "<<a.Carrera<<" "<<a.mensualidad<<endl;
    cout<<"Ejemplo de load: "<<endl; 
    ejemplo.load();
    


}

/* Para escribir un alumno en consola
    string mensualidad;
    cout << "Nombre: ";
    cin >> alumno.Nombre ;
    cout << endl ;
    cout << "Apellido: " ;
    cin >> alumno.Apellidos ;
    cout << endl;
    cout << "Carrera: ";
    cin >> alumno.Carrera;
    cout <<endl;
    cout << "Mensualidad: " ;
    cin >> mensualidad ;
    cout << endl;
    alumno.mensualidad = atof(mensualidad.c_str());
*/



























/*
    do{
        this->Register(file,record);
        vrecord.push_back(record);
    } while(getline(file,line));
*/





















/*
    ostream &operator << (ostream & stream, Alumno & p)
    {
        stream << p.codigo;
        stream << p.nombre;
        stream << p.apellidos;
        stream << p.carrera;
        stream << "\n";
        stream << flush;
        return stream;
    }

    istream &operator >> (istream & stream, Alumno & p)
    {
        stream.get(p.codigo,5);
        stream.get(p.nombre,11);
        stream.get(p.apellidos,20);
        stream.get(p.carrera,15);
        stream.get();
        return stream;

    }


        size_t sizeBytes(){
        size_t size=0;
        size+=sizeof(mensualidad);
        size+=Nombre.length()*sizeof(char);
        size+=Apellidos.length()*sizeof(char);
        size+=Carrera.length()*sizeof(char);
        return size;
    }
*/