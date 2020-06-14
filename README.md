[![C/C++ CI](https://github.com/cs1103-lab2-01-2020-1/pooii-tarea-5-entrega-17-06-otreblan/workflows/C/C++%20CI/badge.svg)](https://github.com/cs1103-lab2-01-2020-1/pooii-tarea-5-entrega-17-06-otreblan/actions?query=workflow%3A%22C%2FC%2B%2B+CI%22)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/cs1103-lab2-01-2020-1/pooii-tarea-5-entrega-17-06-otreblan?logo=github)
![GitHub](https://img.shields.io/github/license/cs1103-lab2-01-2020-1/pooii-tarea-5-entrega-17-06-otreblan?logo=gnu)

# Programación Orientado a Objetos II

<p align="center">
<img src="https://user-images.githubusercontent.com/39320840/84606061-0b70e000-ae68-11ea-859a-b8adffa0ca29.gif">
</p>

Información del Alumno:
-

Nombre: Alberto Oporto Ames
--

Codigo: 201810518
--

Usuario github: otreblan
--

## Tarea 5

1. Desarrollar un programa que notifique a usuarios inscritos los estados
de disponibilidad de espacios de un parqueo, de modo que envíe una alerta
avisando los espacios disponibles cada vez que se libere o ocupe un espacio.


2. Desarrollar un programa de control disponibilidad de mesas en un restaurante,
el programa deberá registrar un número de mesas con un identificador de posición
y entregará, a cada cliente registrado, el estado de las mesas de modo que modo
que actualice al cliente con la cantidad de mesas disponibles cada vez cada vez
que se libere o ocupe.


Requerimientos:

-  Diseñar el sistema graficamente utilizando diagramas de clases y flujos
y agregarlos en la carpeta imagenes con extension .JPG o PDF (No word, no archivo de texto)

- La implementación debe estar dentro de la carpeta `src`

## Build

### Ubuntu >= 20.04

#### Dependencias

- `g++-10`
- `libreadline-dev`
- `libboost-dev`
- `libnotify-dev`

#### Build

``` bash
mkdir -p build && cd build
CXX=g++-10 cmake ..
make -j$(nproc)

./observer
```

### Arch Linux

#### Build

``` bash
cd pkg/arch
makepkg -si

observer
```

## Paquetes

Hay paquetes para Ubuntu en cada [release](https://github.com/cs1103-lab2-01-2020-1/pooii-tarea-5-entrega-17-06-otreblan/releases/latest).
