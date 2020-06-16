const mongoose = require('mongoose');

//const MONGODB_URI = process.env.MONGODB_URI; // en archivo .env esta el valor

//const NOTES_APP_MONGODB_HOST = process.env.NOTES_APP_MONGODB_HOST;
//const NOTES_APP_MONGODB_DATABASE = process.env.NOTES_APP_MONGODB_DATABASE;

//Otra manera de poner todo junto
const {NOTES_APP_MONGODB_HOST, NOTES_APP_MONGODB_DATABASE} = process.env;
const MONGODB_URI = `mongodb://${NOTES_APP_MONGODB_HOST}/${NOTES_APP_MONGODB_DATABASE}`;


mongoose.connect(MONGODB_URI,{
    useUnifiedTopology: true,
    useNewUrlParser: true
})
  .then(db => console.log('Database is connected'))
  .catch(err => console.log(err));