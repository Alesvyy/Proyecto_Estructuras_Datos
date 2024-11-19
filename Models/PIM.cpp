#include "PIM.h" 
void PIM::agregarProducto(const std::string& nombre, const std::string& descripcion, double precio, const std::string& categoria) { 
Producto* nuevoProducto = new Producto(contadorID++, nombre, descripcion, precio, categoria); 
if (!cabeza) { 
cabeza = nuevoProducto; 
} else { 
Producto* temp = cabeza; 
while (temp->siguiente) { 
temp = temp->siguiente; 
} 
temp->siguiente = nuevoProducto; 
} 
std::cout << "Producto agregado con exito.\n"; 
} 
void PIM::eliminarProducto(int id) { 
if (!cabeza) { 
std::cout << "La lista de productos esta vacia.\n"; 
return; 
} 
Producto* temp = cabeza; 
Producto* anterior = nullptr; 
while (temp && temp->id != id) { 
anterior = temp; 
temp = temp->siguiente; 
} 
if (!temp) { 
std::cout << "Producto con ID " << id << " no encontrado.\n"; 
return; 
} 
if (!anterior) { 
cabeza = temp->siguiente; 
} else { 
anterior->siguiente = temp->siguiente; 
} 
delete temp; 
std::cout << "Producto eliminado con exito.\n"; 
} 
void PIM::mostrarProductos() { 
if (!cabeza) { 
std::cout << "No hay productos para mostrar.\n"; 
return; 
} 
Producto* temp = cabeza; 
while (temp) { 
std::cout << "ID: " << temp->id << ", Nombre: " << temp->nombre << ", Descripcion: " << temp->descripcion 
<< ", Precio: $" << temp->precio << ", Categoria: " << temp->categoria << std::endl; 
temp = temp->siguiente; 
} 
} 
void PIM::modificarProducto(int id, const std::string& nombre, const std::string& descripcion, double precio, const std::string& 
categoria) { 
Producto* temp = cabeza; 
while (temp && temp->id != id) { 
temp = temp->siguiente; 
} 
if (temp) { 
temp->nombre = nombre; 
temp->descripcion = descripcion; 
temp->precio = precio; 
temp->categoria = categoria; 
std::cout << "Producto modificado con exito.\n"; 
} else { 
std::cout << "Producto con ID " << id << " no encontrado.\n"; 
} 
} 
void PIM::consultarProducto(int id) { 
Producto* temp = cabeza; 
while (temp && temp->id != id) { 
temp = temp->siguiente; 
} 
if (temp) { 
std::cout << "ID: " << temp->id << ", Nombre: " << temp->nombre << ", Descripcion: " << temp->descripcion 
<< ", Precio: $" << temp->precio << ", Categoria: " << temp->categoria << std::endl; 
} else { 
std::cout << "Producto con ID " << id << " no encontrado.\n"; 
} 
} 
PIM::~PIM() { 
Producto* temp; 
while (cabeza) { 
temp = cabeza; 
cabeza = cabeza->siguiente; 
delete temp; 
} 
}