const express = require('express');
const path = require('path'); // llamo a path para utilizarlo mas abajo en settings

// Initializations
const app = express();

// Settings // lo que quiero que haga express basado en algunos modulos
app.set('port', process.env.PORT||4000); //para que tome un puerto del servidor y si no da tome el 4000
app.set('views', path.join(__dirname,'views')); // se indica en donde esta la carpeta view, __dirname va a dar la carpeta en el servidor que puede ser variable y con path se puede concatener carpetas porque puede cabmbiar de acuerdo al SO

// Middleware // funciones que se ejecutan a medida que llegan peticiones
app.use(express.urlencoded({extended:false})); // Le dice al servidor que cuando llegen los datos de un formulario que se traten de convertir en un objeto json para manipularlo en codigo

// Global Variables // Variables globales para acceder en todo el proyecto

// Routes // Rutas
app.get('/',(req,res)=>{
    res.send('Hello world'); // Defino una ruta basica, nueva ruta nueva url para cuando soliciten una ruta inicial
});

// Static files
app.set(express.static(path.join(__dirname,'public'))); // Se determina en node la carpeta public

module.exports = app;