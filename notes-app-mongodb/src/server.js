const express = require('express');
const exphbs = require('express-handlebars');
const path = require('path'); // llamo a path para utilizarlo mas abajo en settings

// Initializations
const app = express();

// Settings // lo que quiero que haga express basado en algunos modulos
app.set('port', process.env.PORT||4000); //para que tome un puerto del servidor y si no da tome el 4000
app.set('views', path.join(__dirname,'views')); // se indica en donde esta la carpeta view, __dirname va a dar la carpeta en el servidor que puede ser variable y con path se puede concatener carpetas porque puede cabmbiar de acuerdo al SO

//Defino el engine que voy a utilizar para las plantillas
app.engine('.hbs', exphbs({
    defaultLayout: 'main',
    layoutsDir: path.join(app.get('views'),'layouts'),
    partialsDir: path.join(app.get('views'),'partials'),
    extname: '.hbs'
}));
// Luego de definir la declaro para utilizarla
app.set('view engine','.hbs');

// Middleware // funciones que se ejecutan a medida que llegan peticiones
app.use(express.urlencoded({extended:false})); // Le dice al servidor que cuando llegen los datos de un formulario que se traten de convertir en un objeto json para manipularlo en codigo

// Global Variables // Variables globales para acceder en todo el proyecto

// Routes // Rutas
//app.get('/',(req,res)=>{
//    //res.send('Hello world'); // Defino una ruta basica, nueva ruta nueva url para cuando soliciten una ruta inicial
//    res.render('index'); //Ya sabe a donde ir a buscar index porque se declaro views y la extension hbs
//});
// Comento lo anterior para que se utilice index.router.js
app.use(require('./routes/index.routes'));

// Static files
//app.set(express.static(path.join(__dirname,'public'))); // Se determina en node la carpeta public
app.use(express.static(path.join(__dirname,'public'))); // cambie a use porque estaba solo definida

module.exports = app;