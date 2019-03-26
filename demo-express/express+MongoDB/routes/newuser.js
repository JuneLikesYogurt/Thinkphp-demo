var express = require('express');
var router = express.Router();

router.get('/', function(req, res, next) {
    res.render('newuser', { title: 'Add'});
});

module.exports = router;