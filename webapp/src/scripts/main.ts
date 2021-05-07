document.addEventListener('DOMContentLoaded', (event) => {

    const fetchBtn : HTMLElement = <HTMLElement> document.getElementById("fetch");
    fetchBtn.addEventListener("click", (event) => {
        let data  = '';
        console.log("fetching");
        fetch('http://192.168.8.121/sensor')
            .then(function(response) {
                return response.json();
            })
            .then(function(myJson) {

                data=myJson;
                console.log(data);

                const output: HTMLOutputElement = <HTMLOutputElement> document.getElementById("output");
                output.innerText = data;
            });
    });
});