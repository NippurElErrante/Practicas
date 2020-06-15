const express = require('express');
const router = express.Router();

router.get('/users/signin',(req,res)=>{
    //res.send('Ingresando a la app'); //cambio send por render para que tome lo de la ruta
                                       //views/users/signin
    res.render('users/signin');
});

router.get('/users/signup',(req,res)=>{
    //res.send('Formulario de authentication'); //cambio send por render para que tome lo de la ruta
                                                //views/users/signup
    res.render('users/signup');
});

module.exports = router;