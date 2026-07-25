const container = document.getElementById("users");
const url = "https://dummyjson.com/users";   

xhr = new XMLHttpRequest();
xhr.open("GET", url);
xhr.send();

xhr.onload = () => {

    if(xhr.status == 200) {

        const users = JSON.parse(xhr.responseText).users;

        let statusChoice = ['Active', 'Inactive'];
        for(let user of users) { 
            user.status = statusChoice[Math.floor(Math.random() * 2)];
        }

        for(let user of users) {
            container.innerHTML += `<div>${user.firstName} - ${user.status}</div>`;
        }
    }
    else {
        container.innerHtml += '<h1> No users found </h1>'
    }   
}