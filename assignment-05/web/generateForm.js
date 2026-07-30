const form = document.getElementsByTagName("form")[0];

const fields = [
    "First Name",
    "Last Name",
    "Email"
]; 

const generateFunction = () => {

    let rows = fields.map(field => {
        return `<label>${field}</label> : <input type="text"> <br>`;
    });

    rows.forEach(row => form.innerHTML += row);
}

generateFunction();

document.getElementById("parent").addEventListener("click", function(event) {
    console.log(event.target.id, event.currentTarget.id);
});