// const os = require('os');

// console.log(os.platform());
// console.log(os.release());
// console.log('free mem: ', os.freemem(),' bytes');
// console.log('free total: ', os.totalmem(),' bytes');

// ejemplo para ver como utiliza el codigo asincrono
// al ejecutarlo primer aparece el mensaje
// de ultima linea y despues el mensaje
// de archivo creado.
// Esto es porque nodejs le deja la tarea
// al SO y sigue con los comandos

const fs = require('fs');

fs.writeFile('./texto.txt','linea uno',function(err){
  if (err) {
      console.log(err);
  }
  console.log('Archivo creado'); 
});

console.log('Ultima linea del codigo');

// ejemplo metodo query
/*
const users = query('Select * from users');

query('Select * from users', function(err, users){
    if (err){
        console.log();
    }
    if (users) {
        xxxxxxxxx
    }
})
*/