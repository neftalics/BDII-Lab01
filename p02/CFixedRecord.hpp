
#include    "SAlumno.hpp"

class FixedRecord 
{
    private:
    std::string filename ;

    public:
    FixedRecord (std::string &filename_) { filename = filename_; };
    ~FixedRecord(){};
    std::vector<Alumno> load()
    {
        vector<Alumno> vrecord;
        Alumno record;

        ifstream file;

        file.open(filename,ios::binary);

        file.seekg(sizeof(int),ios::beg);

        while(file.read((char*) &record, sizeof(Alumno)) ){
                
                vrecord.push_back(record);
        }
        file.close();
        return vrecord;
    };

    void add(Alumno record){
        ofstream file(filename, ios::app | ios::binary);
        // if(!file.is_open()) throw Exception("No se pudo abrir el archivo");

        file.write((char*) &record, sizeof(Alumno));//guardar en formato binario
        file.close();
    };
    Alumno readRecord(int pos){
        std::ifstream file(filename, ios::binary);
        // if(!file.is_open()) throw Exception("No se pudo abrir el archivo");

        Alumno record;
        file.seekg(pos * sizeof(Alumno), ios::beg);//fixed length record
        file.read((char*) &record, sizeof(Alumno));
        file.close();
        return record;
    };

};
