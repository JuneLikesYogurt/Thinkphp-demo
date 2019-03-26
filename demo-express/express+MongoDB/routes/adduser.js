var express = require('express');
var router = express.Router();

var mongo = require('mongodb');
var monk = require('monk');
var db = monk('127.0.0.1:27017/AccountsCenter');

router.post('/', function (req, res, next) {
    var email = req.body.email;
    var name = req.body.name;

    var collection = db.get('feidian');

    collection.insert({
        "email": email,
        "name": name
    }, function (err, doc) {
        if(err) {
            res.send("There was a problem adding the information to the database.");
        } else {
            res.location("datas");
            res.redirect("datas");
        }
    });
});

module.exports = router;