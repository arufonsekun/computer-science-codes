const http = require("http");
const fs = require("fs");
const treejs = require("treejs");

const server = http.createServer((request, response) => {

    fs.readFile(`${__dirname}/index.html`, (e, html) => {

        if (e) throw e;

        else {
            response.writeHeader(200, {"content-Type" : "text/html"});
            response.write(html);
            response.end();

        }

    });


});

server.listen(3000, () => {
    console.log("Server is up and running at localhost:3000")
});
