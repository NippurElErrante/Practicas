// Para iniciar npm run dev
// Para iniciar mongodb se debe prender el servicio y luego llamar a la base
// C:\Program Files\MongoDB\Server\4.2\bin\mongod.exe
// C:\Program Files\MongoDB\Server\4.2\bin\mongo.exe
// tiempo del video 47
const express = require('express');
const path = require('path');
const exphbs = require('express-handlebars');
const methodOverride = require('method-override');
const session = require('express-session');

// Initializations
const app = express();
require('./database');


// Settings -- Todas las configuraciones
app.set('port', process.env.PORT || 3000);
// con _dirname toma el path actual
app.set('views', path.join(__dirname,'views'));
app.engine('.hbs',exphbs({
    defaultLayout:'main',
    layoutsDir:path.join(app.get('views'),'layouts'),
    partialsDir:path.join(app.get('views'),'partials'),
    extname:'.hbs'
}));
// con lo siguiente configuro el motor de las vistas
app.set('view engine','.hbs');

// Midlewares -- Todas las funciones que seran ejecutadas antes de llegar al servidor
//            -- o antes de pasarselo a las rutas cuando llegan al servidor
app.use(express.urlencoded({extended:false}));
app.use(methodOverride('_method'));
app.use(session({
    secret: 'mysecretapp',
    resave: true,
    saveUninitialized: true
}));


// Global Variables -- Colocar ciertos datos para que esten accesibles a toda la aplicacion

// Routes
app.use(require('./routes/index'));
app.use(require('./routes/notes'));
app.use(require('./routes/users'));

// Static Files -- Configurar donde estarn los archivos estaticos
app.use(express.static(path.join(__dirname,'public')));

// Server is listenning
app.listen(app.get('port'), () => {
    console.log('Server on port', app.get('port'));
});