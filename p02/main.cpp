
#include    "CFixedRecord.hpp"

int main(int argc , char** argv){
    std::string x = "datos.dat";

    FixedRecord fr ( x );
    vector<Alumno> aea = fr.load();
    // for (auto i:aea )
    // {
    //     cout<<i.codigo<<i.nombre<<i.apellidos<<i.carrera<<endl;
    // }
    // Alumno alumno={"0008"," Howqw","Paredes Zeaaa","Comuaaaa"};
    // fr.add(alumno);
    // Alumno a;
    // a=fr.readRecord(7);
    
    // cout<<a.codigo<<a.nombre<<a.apellidos<<a.carrera<<endl;

    


    return 0;
}