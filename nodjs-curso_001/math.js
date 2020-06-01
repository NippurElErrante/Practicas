const Math = {};

function add(x1,x2){
    return x1 + x2 ;
}

function substract(x1,x2){
    return x1 - x2 ;
}

function multiply(x1,x2){
    return x1 * x2 ;
}

function divide(x1,x2){
    if (x2 == 0) {
        console.log('No se puede dividir por 0');
    } else {
        return x1 / x2 ;
    }
}
// para hacer un export individual
// exports.add = add;
// exports.substract = substract;
// exports.multiply = multiply;
// exports.divide = divide;

Math.add = add;
Math.substract = substract;
Math.multiply = multiply;
Math.divide = divide;

// de esta manera exporto el objeto entero
module.exports = Math;

// tambien se pueden exportar funciones
/*
function hello(name){
    console.log('Hola', name);
}
module.exports = hello;
*/