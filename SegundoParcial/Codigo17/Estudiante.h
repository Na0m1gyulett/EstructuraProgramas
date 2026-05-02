#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante{
private:
	std::string nombre;
	float calificacion;
	
public:
	Estudiante();
	Estudiante(std::string nombre, float calificacion);
	
	std::string getNombre() const;
	float getCalificacion() const;
	
	void mostrar() const;
};

#endif