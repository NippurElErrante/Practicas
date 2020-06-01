// buscar anexo codigos de estado http en wikipedia
const http = require('http');

const handleServer = function(req,res){
    // res.writeHead(200,{'Content-type':'text/html'});
    // Si quiero manejar un codigo de error
    // por ejemplo 404
    // res.writeHead(404,{'Content-type':'text/plain'});
    res.writeHead(200,{'Content-type':'text/plain'});
    // res.write('<h1>Hola Mundo desde Nodejs</h1>');
    // res.write('<h1>Hola Mundo</h1>');
    res.write('Texto plano');
    res.end();
}

http.createServer(handleServer).listen(3000);
