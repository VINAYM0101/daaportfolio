// Dynamic JavaScript for Algorithm Visualizations and Interactivity

document.addEventListener('DOMContentLoaded', () => {
    // Smooth Scroll for Navigation Links
    const navLinks = document.querySelectorAll('.nav ul li a');
    navLinks.forEach(link => {
        link.addEventListener('click', event => {
            event.preventDefault();
            const targetId = link.getAttribute('href').substring(1);
            const targetElement = document.getElementById(targetId);
            if (targetElement) {
                targetElement.scrollIntoView({ behavior: 'smooth' });
            }
        });
    });

    // Canvas for Algorithm Visualizations
    const canvas = document.getElementById('algorithmCanvas');
    if (canvas) {
        const ctx = canvas.getContext('2d');
        const width = canvas.width = canvas.parentElement.offsetWidth;
        const height = canvas.height = canvas.parentElement.offsetHeight;

        // Example: Bubble Sort Visualization
        let array = [];
        for (let i = 0; i < 50; i++) {
            array.push(Math.floor(Math.random() * height));
        }

        function drawArray() {
            ctx.clearRect(0, 0, width, height);
            for (let i = 0; i < array.length; i++) {
                ctx.fillStyle = '#4a90e2';
                ctx.fillRect(i * (width / array.length), height - array[i], width / array.length - 2, array[i]);
            }
        }

        async function bubbleSort() {
            for (let i = 0; i < array.length; i++) {
                for (let j = 0; j < array.length - i - 1; j++) {
                    if (array[j] > array[j + 1]) {
                        [array[j], array[j + 1]] = [array[j + 1], array[j]];
                        drawArray();
                        await new Promise(resolve => setTimeout(resolve, 50));
                    }
                }
            }
        }

        // Initial Draw
        drawArray();

        // Start Bubble Sort on Button Click
        document.querySelector('.visualizations').addEventListener('click', () => {
            bubbleSort();
        });
    }

    // Quiz Interactivity
    const quizButton = document.querySelector('.quiz-button');
    if (quizButton) {
        quizButton.addEventListener('click', () => {
            alert('Quiz functionality will be added soon!');
        });
    }

    // Responsive Canvas Resize
    window.addEventListener('resize', () => {
        if (canvas) {
            canvas.width = canvas.parentElement.offsetWidth;
            canvas.height = canvas.parentElement.offsetHeight;
            drawArray();
        }
    });
});
