#include <stdio.h>
#include <string.h>

int main()
{
    char nombres[10][50],buscar[50];;
    float precios[10];
    float suma = 0,total = 0;
    int cant= 0,encontrado = 0, mayor = 0, menor = 0;
    int opcion,i,c;
    
    do
    {
        printf("\n MENU DE OPCIONES \n");
        printf("1. Registrar producto\n");
        printf("2. Mostrar el precio total del inventario\n");
        printf("3. Mostrar el producto con mayor y menor precio\n");
        printf("4. Mostrar el promedio de los productos\n");
        printf("5. Buscar un producto por nombre\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        if (scanf("%d", &opcion) != 1) { 
            while (getchar() != '\n')
            opcion = 0; 
        }

        switch(opcion)
        {
            case 1:

                if(cant < 10)
                {
                    printf("Ingrese el nombre del producto: ");
                    scanf("%s", nombres[cant]);
                    do 
                    {
                        printf("Ingrese el precio del producto: ");
                        if (scanf("%f", &precios[cant]) != 1) {
                            printf("\nError: Entrada invalida. Por favor ingrese un numero.\n");
                            while (getchar() != '\n');
                            precios[cant] = -1; 
                        }
                        else if (precios[cant] <= 0) {
                            printf("\nError: El precio debe ser mayor a cero.\n");
                        }
                    } while (precios[cant] <= 0);
                    cant++;

                    printf("\nProducto registrado correctamente.\n");
                }
                else
                {
                    printf("No se pueden registrar mas de 10 productos.\n");
                }

                break;


            case 2:

                total = 0;

                for(i = 0; i < cant; i++)
                {
                    total = total + precios[i];
                }

                printf("El precio total del inventario es: %.2f\n", total);

                break;


            case 3:

                if(cant == 0)
                {
                    printf("No hay productos registrados.\n");
                }
                else
                {
                    mayor = 0;
                    menor = 0;

                    for(i = 1; i < cant; i++)
                    {
                        if(precios[i] > precios[mayor])
                        {
                            mayor = i;
                        }

                        if(precios[i] < precios[menor])
                        {
                            menor = i;
                        }
                    }

                    printf("Producto con mayor precio: %s\n", nombres[mayor]);
                    printf("Precio: %.2f\n", precios[mayor]);

                    printf("Producto con menor precio: %s\n", nombres[menor]);
                    printf("Precio: %.2f\n", precios[menor]);
                }

                break;


            case 4:

                if(cant== 0)
                {
                    printf("No hay productos registrados.\n");
                }
                else
                {
                    suma = 0;

                    for(i = 0; i < cant; i++)
                    {
                        suma = suma + precios[i];
                    }

                    printf("El promedio de los productos es: %.2f\n",
                           suma / cant);
                }

                break;


            case 5:

                if(cant == 0)
                {
                    printf("No hay productos registrados.\n");
                }
                else
                {


                    printf("Ingrese el nombre del producto a buscar: ");
                    scanf("%s", buscar);

                    encontrado = 0;

                    for(i = 0; i < cant; i++)
                    {
                        if(strcmp(nombres[i], buscar) == 0)
                        {
                            printf("Producto encontrado: %s\n", nombres[i]);
                            printf("Precio: %.2f\n", precios[i]);

                            encontrado = 1;
                        }
                    }

                    if(encontrado == 0)
                    {
                        printf("Producto no encontrado.\n");
                    }
                }

                break;


            case 6:

                printf("Programa finalizado.\n");

                break;


            default:

                printf("\nOpcion invalida. Intente nuevamente.\n");

                break;
        }

        if(opcion != 6)
        {
            printf("\nDesea seleccionar otra opcion 1.Si/2.No: ");
            while (scanf("%d", &c) != 1 || (c != 1 && c != 2)) {
                printf("Error: Ingrese 1 para Si, o 2 para No: ");
                while (getchar() != '\n');
        }
        }

    } while(c == 1 && opcion != 6);

    return 0;
}


