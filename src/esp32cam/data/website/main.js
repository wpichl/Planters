function init() {
    window.location.hash = '#first';
    startTime();
}
document.addEventListener('DOMContentLoaded', (event) => {
    const fetchBtn = document.getElementById("fetch");
    fetchBtn.addEventListener("click", (event) => {
        fetch('http://192.168.0.2/sensor')
            .then(response => response.text())
            .then(data => {
            console.log(data);
            const obj = JSON.parse(data);
            console.log(obj.sensor);
            const sensordiv = document.getElementById("sensorvalues");
            sensordiv.innerText = `Plant dryness: ${obj.dryness}%\n Waterable: ${obj.waterable}`;
        });
    });
    const waterBtn = document.getElementById("water");
    waterBtn.addEventListener("click", (event) => {
        fetch('http://192.168.0.2/water')
            .then(response => response.text())
            .then(data => {
            console.log(data);
            const waterdiv = document.getElementById("watering");
            waterdiv.innerText = data;
        });
    });
    let enabled = true;
    const enabledBtn = document.getElementById("inputToggle");
    enabledBtn.addEventListener("click", (event) => {
        enabled = !enabled;
        if (enabled) {
            fetch('http://192.168.0.2/enableautomatic')
                .then(response => response.text())
                .then(data => {
                console.log(data);
                const outputdiv = document.getElementById("buttonoutput");
                outputdiv.innerText = data;
            });
        }
        else {
            fetch('http://192.168.0.2/disableautomatic')
                .then(response => response.text())
                .then(data => {
                console.log(data);
                const outputdiv = document.getElementById("buttonoutput");
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
    if (i < 10) {
        i = "0" + i;
    }
    ; // add zero in front of numbers < 10
    return i;
}

document.addEventListener('DOMContentLoaded', (event) => {
    fetch('http://192.168.0.2/stats')
        .then(response => response.text())
        .then(data => {
            const chartdata = JSON.parse(data);
            new Chart("myChart", {
                type: "line",
                data: {
                    labels: Object.keys(chartdata),
                    datasets: [{
                        data: Object.values(chartdata)
                    }]
                },
                options: {
                    legend: {display: false},
                    title: {
                        display: true,
                        text: "Number of watering processes"
                    }
                }
            });
        });
});
//# sourceMappingURL=main.js.map