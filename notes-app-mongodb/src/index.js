require('dotenv').config(); // Aca se declara para utilizar dotenv
                            // esto es para que se lea el archivo .env
                            // del directorio raiz para que puede configurar
                            // valores ahi solo para la etapa de desarrollo
                            // y que no queden en la etapa productiva
                            // por ejemplo alguna ruta o datos de base
                            // que es riesgoso que este publicas
                            // tiene que ir primero para que cargue esas variables
                            // el archivo .env no sube al servidor productivo

const app = require('./server');

require('./database');

//console.log(process.env.TESTING); //para imprimir por consolta un ejemplo de variable local de entorno

app.listen(app.get('port'),()=> {
    console.log('Server on port ',app.get('port'));
})