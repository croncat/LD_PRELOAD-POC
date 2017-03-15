# LD_PRELOAD-POC

RMDIR POC
=========

$ cd Preload/
$ make
$ ./preload.sh

ENJOY :)

GENERAL INFO (in english soon)
==============================

Toda pieza de software es factible de ser reutilizada. En cualquier sistema operativo moderno, podemos encontrar mecanismos para poder desarrollar diversos programas que interactuen con piezas de software en común. Los sistemas operativos tipo UNIX no son la excepción.

Esta posibilidad se abre seriamente para UNIX en el año 1988, con el lanzamiento de System V Release 4.0, que fue un esfuerzo conjunto de AT&T Unix System Laboratories y Sun Microsystems. Desde ese momento tenemos en la calle al formato ELF (Executable and Linkable Format) que es un formato de archivo para ejecutables, código objeto, bibliotecas compartidas y volcados de memoria. Fue desarrollado por Unix System Laboratories (USL) como parte de la ABI. Es el formato ejecutable usado mayoritariamente en los sistemas tipo UNIX como GNU/Linux, BSD, Solaris, Irix.

Por qué digo que fue en este momento? Porque para realizar una reutilización de código realmente bien encarada, necesitamos contar, en la ABI, con un mecanismo de enlace dinámico entre binarios. Bajando esto un poco a tierra, aparecen los maravillosos Shared Objects!

[Hay una implementación anterior a ELF, que son los COFF (Common Object File Format) que aparece en 1983, pero el diseño de COFF era limitado e incompleto: había un límite en el número máximo de secciones, un límite en la longitud de los nombres de sección incluyendo archivos fuente, y la información simbólica de depuración era incapaz de soportar lenguajes como C, y mucho menos lenguajes más nuevos como C++ o de soportar nuevos procesadores. Como resultado de esto, en el mundo real, todas las implementaciones de COFF necesariamente fueron violaciones de los estándares.]

¿Qué son los shared objects?
No son ni más ni menos que bibliotecas dinámicas: son ficheros que contienen código objeto construido de forma independiente a su ubicación de tal modo que están preparadas para poder ser requeridas y cargadas en tiempo de ejecución por cualquier programa, en lugar de tener que ser enlazadas, previamente, en tiempo de compilación. Por tanto, han de estar disponibles como ficheros independientes al programa ejecutable (generalmente en directorios del sistema).

En el caso de ELF, se expresan:
EXEC: ejecutable
REL: reubicable (libreria estática)
DYN: objeto compartido (libreria dinámica)

Comandos a utilizar:
readelf -h NAME (cabecera)
readelf -s NAME (simbolos)
objdump -p NAME (dependencias dinámicas)
ldd NAME (dependencias dinámicas)
nm -D -C NAME (only dynamic symbols and correct names in C++)

Manual:
man ld.so
man dlsym
man gcc (for PIC and shared)
