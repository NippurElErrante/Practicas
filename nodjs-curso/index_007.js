/*
Utiliacion de NPM para armado json
npm install colors -- para instalar un modulo
npm i colors -- es igual al anterior pero resumido
npm init -- es para que se genera el instalador
npm install -- es lo que ejecuta el servidor
               al leer el pkg json
               tambien lo arma
npm start -- se usa para iniciar el programa
          -- ejecuta lo que encuentra en 
          -- la seccion de scripts
          -- en start
npm run desarrollo -- ejemplo, si quiero
                   -- que se ejecute un script
                   -- por npm que no sea start
*/
const http = require('http');

const colors = require('colors');

const handleServer = function(req,res){
    res.writeHead(200, {'Content-type':'text/html'});
    res.write('<h1>Hola Mundo</h1>');
    res.end();
}

const server = http.createServer(handleServer);

server.listen(3000, function(){
    console.log('Server on port 3000'.green);
});