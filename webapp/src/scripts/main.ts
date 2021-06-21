function init()
{
    window.location.hash = '#first';
    startTime();
}

document.addEventListener('DOMContentLoaded', (event) => {
    const fetchBtn : HTMLElement = <HTMLElement> document.getElementById("fetch");
    fetchBtn.addEventListener("click", (event) => {
        fetch('http://192.168.0.2/sensor')
            .then(response => response.text())
            .then(data => {
                console.log(data);
                const obj = JSON.parse(data);
                console.log(obj.sensor);
                const sensordiv : HTMLOutputElement = <HTMLOutputElement> document.getElementById("sensorvalues");
                sensordiv.innerText = `Plant dryness: ${obj.dryness}%\n Waterable: ${obj.waterable}`;
            });
    });
    const waterBtn : HTMLElement = <HTMLElement> document.getElementById("water");
    waterBtn.addEventListener("click", (event) => {
        fetch('http://192.168.0.2/water')
            .then(response => response.text())
            .then(data => {
                console.log(data);
                const waterdiv : HTMLOutputElement = <HTMLOutputElement> document.getElementById("watering");
                waterdiv.innerText = data;
            });
    });
    let enabled = true;
    const enabledBtn : HTMLElement = <HTMLElement> document.getElementById("inputToggle");
    enabledBtn.addEventListener("click", (event) => {
        enabled = !enabled;
        if(enabled)
        {
            fetch('http://192.168.0.2/enableautomatic')
                .then(response => response.text())
                .then(data => {
                    console.log(data);
                    const outputdiv : HTMLOutputElement = <HTMLOutputElement> document.getElementById("buttonoutput");
                    outputdiv.innerText = data;
                });
        }
        else
        {
            fetch('http://192.168.0.2/disableautomatic')
                .then(response => response.text())
                .then(data => {
                    console.log(data);
                    const outputdiv : HTMLOutputElement = <HTMLOutputElement> document.getElementById("buttonoutput");
                    outputdiv.innerText = data;
                });
        }
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
    document.getElementById('txt2').innerHTML =
        h + ":" + m + ":" + s;
    document.getElementById('txt3').innerHTML =
        h + ":" + m + ":" + s;
    let t = setTimeout(startTime, 1000);
}
function checkTime(i) {
    if (i < 10) {i = "0" + i};  // add zero in front of numbers < 10
    return i;
}




