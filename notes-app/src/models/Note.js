const mongoose = require('mongoose');
const { Schema } = mongoose;

const NoteSchema = new Schema({
    title:{type:String,required:true},
    description:{type:String, required:true},
    date:{type:Date,default:Date.now}
})

module.exports = mongoose.model('Note',NoteSchema)

// Para consultar a la base de datos lo que se crea
// se abre una terminal y se escribe mongo
// el servicio esta inicializado, solo llamo al cliente
// Primero llamo a la base que esta en database.js
// use notes-db-app
// da mensaje que se cambio a esa base switched to db notes-db-app
// luego veo lo que tiene con
// show collections
// luego veo lo que tiene guardado
// db.notes.find().pretty()
// Para eliminar la base de datos
// db.dropDatabase()
// si devuelve ok :1 es que fue eliminada