
document.addEventListener('DOMContentLoaded', (event) => {

    const fetchBtn : HTMLElement = <HTMLElement> document.getElementById("fetch");
    fetchBtn.addEventListener("click", (event) => {
        let data  = ''
        console.log("fetching")
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

function startTime() {
    let today = new Date();
    let h = today.getHours();
    let m = today.getMinutes();
    let s = today.getSeconds();
    m = checkTime(m);
    s = checkTime(s);
    document.getElementById('txt').innerHTML =
        h + ":" + m + ":" + s;
    let t = setTimeout(startTime, 1000);
}
function checkTime(i) {
    if (i < 10) {i = "0" + i};  // add zero in front of numbers < 10
    return i;
}

//# sourceMappingURL=main.js.map
