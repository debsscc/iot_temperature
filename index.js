const body = document.body;
const h1 = document.querySelector("h1");
const button = document.querySelector("button");
const sun = document.querySelector("#sun");
const moon = document.querySelector("#moon");
button.addEventListener("click", () => {
  body.classList.contains("dark-mode")
    ? body.classList.remove("dark-mode")
    : body.classList.add("dark-mode");
  sun.classList.toggle("hidden");
  moon.classList.toggle("hidden");
});
document.body.appendChild(button);

setInterval(() => {
  fetch(
    "https://api.thingspeak.com/channels/2982060/feeds.json?api_key=XFXEN1POQVE8T8ER&results=1"
  )
    .then((response) => response.json())
    .then((data) => {
      const weather = data.feeds[0];
      h1.textContent = `${weather.field1}°C ${weather.field2} %`;
    })
    .catch((error) => {
      console.error("Error fetching data:", error);
      h1.textContent = `Erro: ${error}.`;
    });
}, 1000);

body.classList.add("dark-mode");
