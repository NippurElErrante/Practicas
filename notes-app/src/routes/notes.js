// En este archivo de las rutas le indico donde estaran las acciones
// para las notas, luego las va a buscar
// a las vistas (views) para cada accion
const express = require('express');
const router = express.Router();

const Note = require('../models/Note');

router.get('/notes/add',(req,res)=>{
    res.render('notes/new-note');
});

// router.post('/notes/new-note',(req,res)=>{
// se le agrega async para que grabe
// indica que existiran procesos asincronos
router.post('/notes/new-note', async (req,res)=>{
  //console.log(req.body); // con console.log lo muestro por consola
                           // es temporario porque el fin es guardarlo
                           // en la base de datos
  const {title,description} = req.body;
  const errors = [];
  if (!title){
    errors.push({text: 'Please Write a Title'});
  }
  if (!description){
    errors.push({text: 'Please Write a Description'});
  }
  if (errors.length > 0){
      res.render('notes/new-note',{
          errors,
          title,
          description
      });
    } else{
      // res.send('Ok'); // envia mensaje de Ok
      const newNote = new Note({title,description});
      // console.log(newNote); // muestra por consola lo que guarde en el objeto de la clase
                               // no se guardo en la base, solo se muestra el objeto
      await newNote.save(); // Guarda en la base, con await se hace para que espere
                            // previo a esto en router.post mas arriba se le agrega async
                            // para que sea asincrono
      res.redirect('/notes');
      // res.send('Ok');
    };
});

// Inicio seccion comentada por problemas de version
//router.get('/notes', async (req,res)=>{
//    //res.send('Notes from database'); // para ver un mensaje
//    const notes = await Note.find();
//    res.render('notes/all-notes',{notes});
//});
// Fin seccion comentada por problemas de version

// Un pequenisimo aporte en el minuto 1:27:43, debido a el express-handlerbars que se instala a
// fecha de 13/Feb/2020 es la version 3.1.0 y la version que usa nuestro Jeday @Fazt es la version
// 3.0.0. Esta actualizacion implica que no se pueden acceder a los elementos title y description
// de forma diracta en el archivo all-notes.hbs cuando es llamado desde
// res.render('notes/all-notes',{ notes }) del archivo routes/notes.js.
// Basicamente se debe a una proteccion para evitar ataques de XSS y RCE.
// En stackoverflow.com hay varios post que enseñan a como saltarse esta proteccion,
// lo cual no es nada recomendable, lo mejor es aprender a trabajar con esta nueva condicion.
// Una opcion es crear un nuevo objeto para prevenir la exposicion no deseada de los datos, asi:
router.get('/notes', async (req, res) => {
  await Note.find().sort({date:'desc'}) // agrego sort para que ordene las tarjetas nuevas a viejas
    .then(documentos => {
      const contexto = {
          notes: documentos.map(documento => {
          return {
              title: documento.title,
              description: documento.description
          }
        })
      }
      res.render('notes/all-notes', {
notes: contexto.notes }) 
    })
})

// router.get('/notes/edit/:id', async (req,res)=>{
//   const note = await Note.findById(req.params.id); // Busco en la base de datos
//                                                    // y se guarda en constante
//   res.render('notes/edit-note',{note});
// });
//router.get("/notes/edit/:id", isAuthenticated, renderEditForm);
router.get('/notes/edit/:id', async (req, res) => {
  const note = await Note.findById(req.params.id)
  .then(data =>{
      return {
          title:data.title,
          description:data.description,
          id:data.id
      }
  })
  res.render('notes/edit-note',{note})
});

module.exports = router;