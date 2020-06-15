// Una manera de escribir
//const router = require('express').Router();
// Otra mas practica
const express = require('express');
const router = express.Router();

router.get('/',(req,res)=>{
    //res.send('Index'); // reemplazo .send por render
    res.render('index'); // reemplazo .send por render
});

router.get('/about',(req,res)=>{
    //res.send('About'); // reemplazo .send por render
    res.render('about');
});

module.exports = router;