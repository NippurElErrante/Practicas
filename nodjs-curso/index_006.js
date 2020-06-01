const http = require('http');

const colors = require('colors');

const handleServer = function(req,res){
    // res.writeHead(404,{'Content-type':'text/plain'});
    res.writeHead(200, {'Content-type':'text/html'});
    // res.write('Esto es un simple texto');
    res.write('<h1>Hola Mundo</h1>');
    res.end();
}

// http.createServer(handleServer).listen(3000);

const server = http.createServer(handleServer);

server.listen(3000, function(){
    console.log('Server on port 3000'.green);
});