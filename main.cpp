#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <thread>
#include <chrono>
#include <string>
using namespace sf;

void randomizeArray(std::vector<int>& arr, int minVal, int maxVal) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minVal, maxVal);
    for (int& val : arr) {
        val = dis(gen);
    }
}

void resultswindow(int mergecomp, int bubblecomp, int insertcomp, int selectcomp, String result) {
    RenderWindow resultwindow(VideoMode({500, 300}), "Sorting Algorithm Comparisons");
    Font font("C:\\Windows\\Fonts\\Arial.ttf");

    Text resultTitle(font, result, 24);
    resultTitle.setPosition({20.f, 0.f});
    resultTitle.setFillColor(Color::Black);

    Text mergeText(font, "Merge Sort Comparisons: " + std::to_string(mergecomp), 20);
    mergeText.setPosition({20.f, 30.f});
    mergeText.setFillColor(Color::Black);

    Text bubbleText(font,"Bubble Sort Comparisons: " + std::to_string(bubblecomp), 20);
    bubbleText.setPosition({20.f, 80.f});
    bubbleText.setFillColor(Color::Black);

    Text insertText(font, "Insertion Sort Comparisons: " + std::to_string(insertcomp), 20);
    insertText.setPosition({20.f, 130.f});
    insertText.setFillColor(Color::Black);

    Text selectText(font, "Selection Sort Comparisons: " + std::to_string(selectcomp), 20);
    selectText.setPosition({20.f, 180.f});
    selectText.setFillColor(Color::Black);

    while (resultwindow.isOpen()) {
        while (auto event = resultwindow.pollEvent()) {
            if (event->is < Event::Closed>())
                resultwindow.close();
        }

        resultwindow.clear(Color::White);
        resultwindow.draw(resultTitle);
        if (mergecomp != 0)
        resultwindow.draw(mergeText);
        if (bubblecomp != 0)
        resultwindow.draw(bubbleText);
        if (insertcomp != 0)
        resultwindow.draw(insertText);
        if (selectcomp != 0)
        resultwindow.draw(selectText);
        resultwindow.display();
    }
}

void drawData(const std::vector<int>& data, sf::RenderWindow& window) {
    for (size_t i = 0; i < data.size(); ++i) {
        sf::RectangleShape rectangle(sf::Vector2f(50.f, static_cast<float>(data[i]) * 10.f));
        rectangle.setFillColor(sf::Color::Green);
        rectangle.setPosition(sf::Vector2f(static_cast<float>(i) * 55.f, static_cast<float>(window.getSize().y) - static_cast<float>(data[i]) * 10.f));
        rectangle.setFillColor(sf::Color::Blue);
        window.draw(rectangle);
    }

}

class button{
public:
    RectangleShape shape;
    Text text;
    button(float x, float y, float width, float height, const Font& font, const std::string& str, unsigned int charSize, Color c):text(font, str, charSize) {
        shape.setPosition({x, y});
        shape.setSize({width, height});
        shape.setFillColor(c);

        text.setFont(font);
        text.setString(str);
        text.setCharacterSize(charSize);
        text.setFillColor(Color::White);
        FloatRect textRect = text.getLocalBounds();
        text.setOrigin({textRect.position.x + textRect.size.x / 2.0f,
                       textRect.position.y + textRect.size.y / 2.0f});
        text.setPosition({x + width / 2.0f, y + height / 2.0f});
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }

    bool isMouseOver(sf::RenderWindow& window) {
        Vector2i mousePos = sf::Mouse::getPosition(window);
        FloatRect buttonBounds = shape.getGlobalBounds();
        return buttonBounds.contains({static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)});
    }
};

class SortVisualizer {
public:

    void insertionsort(std::vector<int> data, sf::RenderWindow& window, int& comparisons) {
    size_t n = data.size();
    for (size_t i = 1; i < n; ++i) {
        int key = data[i];
        int j = static_cast<int>(i) - 1;
        while (j >= 0) {
            comparisons++;
            if (data[j] > key) {
                data[j + 1] = data[j];
                insertdrawData(data, window, j, i, comparisons);
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                --j;
            } else {
                break;
            }
        }
        data[j + 1] = key;
        insertdrawData(data, window, j + 1, i, comparisons);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    drawcomplete(data, window, comparisons);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}


    void selectionsort(std::vector<int> data, sf::RenderWindow& window, int& comparisons) {
        size_t n = data.size();
        for (size_t i = 0; i < n - 1; ++i) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < n; ++j) {
                comparisons++;
                selectdrawData(data, window, j, i, comparisons);
                sleep(std::chrono::milliseconds(50));
                if (data[j] < data[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                std::swap(data[i], data[minIndex]);
                selectdrawData(data, window, minIndex, i, comparisons);
                std::this_thread::sleep_for(std::chrono::milliseconds(60));
            }
        }
        drawcomplete(data, window, comparisons);
        sleep(std::chrono::milliseconds(1000));
    }
    
    void bubblesort(std::vector<int> data, sf::RenderWindow& window, int& comparisons) {
        int n= data.size();
        for (int i = 0; i < n - 1; ++i) {
            bool swapped = false;
            for (size_t j = 0; j < n - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                    swapped = true;
                }
                comparisons++;
                bubbledrawData(data, window, j, i, comparisons);
                std::this_thread::sleep_for(std::chrono::milliseconds(50));

            }
            if (!swapped) {
                break;
            }
        }
        drawcomplete(data, window, comparisons);
    }

    void mergesort(std::vector<int>& data, int left, int right, sf::RenderWindow& window, int& comparisons) {
        comparisons++;
        if (left >= right) return;
        int mid = (left + right) / 2;
        mergesort(data, left, mid, window, comparisons);
        mergesort(data, mid + 1, right, window, comparisons);
        merge(data, left, mid, right, window, comparisons);
    }

    void drawcomplete(const std::vector<int>& data, sf::RenderWindow& window, int comparisons=0) {
        window.clear(sf::Color::White);
        for (size_t i = 0; i < data.size(); ++i) {
            Font font("C:\\Windows\\Fonts\\Arial.ttf");
            Text text(font,"Comparisons: "+std::to_string(comparisons), 24);
            text.setFillColor(sf::Color::Black);
            text.setPosition({10.f, 10.f});
            window.draw(text);
            sf::RectangleShape rectangle(sf::Vector2f(50.f, static_cast<float>(data[i]) * 10.f));
            rectangle.setFillColor(sf::Color::Green);
            rectangle.setPosition(sf::Vector2f(static_cast<float>(i) * 55.f, static_cast<float>(window.getSize().y) - static_cast<float>(data[i]) * 10.f));
            window.draw(rectangle);
        }
        window.display();
        sleep(std::chrono::milliseconds(1000));
    }

private:
    void insertdrawData(const std::vector<int>& data, sf::RenderWindow& window, int select, int done, int comparisons) {
        window.clear(sf::Color::White);
    for (size_t i = 0; i < data.size(); ++i) {
        sf::RectangleShape rectangle(sf::Vector2f(50.f, static_cast<float>(data[i]) * 10.f));
        rectangle.setPosition(sf::Vector2f(static_cast<float>(i) * 55.f, static_cast<float>(window.getSize().y) - static_cast<float>(data[i]) * 10.f));
        rectangle.setFillColor(sf::Color::Blue);
        if (i < static_cast<size_t>(done)) {
            rectangle.setFillColor(sf::Color::Green);
        }
        if (i == static_cast<size_t>(select)) {
            rectangle.setFillColor(sf::Color::Red);
        }

        window.draw(rectangle);
    }
        Font font("C:\\Windows\\Fonts\\Arial.ttf");
        Text text(font,"Insertion sort \nComparisons: "+std::to_string(comparisons), 24);
        text.setFillColor(sf::Color::Black);
        text.setPosition({10.f, 10.f});
        window.draw(text);
        window.display();
    }

    void selectdrawData(const std::vector<int>& data, sf::RenderWindow& window, int select, int done, int comparisons) {
        window.clear(sf::Color::White);
        for (size_t i = 0; i < data.size(); ++i) {
            sf::RectangleShape rectangle(sf::Vector2f(50.f, static_cast<float>(data[i]) * 10.f));
            rectangle.setFillColor(sf::Color::Blue);
            rectangle.setPosition(sf::Vector2f(static_cast<float>(i) * 55.f, static_cast<float>(window.getSize().y) - static_cast<float>(data[i]) * 10.f));
            if (i == select || i == done) {
                rectangle.setFillColor(sf::Color::Red);
            }
            if (i < done) {
                rectangle.setFillColor(sf::Color::Green);
            }
            window.draw(rectangle);
        }
        Font font("C:\\Windows\\Fonts\\Arial.ttf");
        Text text(font,"Selection sort \nComparisons: "+std::to_string(comparisons), 24);
        text.setFillColor(sf::Color::Black);
        text.setPosition({10.f, 10.f});
        window.draw(text);
        window.display();
    }
    
    void bubbledrawData(const std::vector<int>& data, sf::RenderWindow& window, int select, int done, int comparisons) {
        window.clear(sf::Color::White);
        for (size_t i = 0; i < data.size(); ++i) {
            sf::RectangleShape rectangle(sf::Vector2f(50.f, static_cast<float>(data[i]) * 10.f));
            rectangle.setFillColor(sf::Color::Blue);
            rectangle.setPosition(sf::Vector2f(static_cast<float>(i) * 55.f, static_cast<float>(window.getSize().y) - static_cast<float>(data[i]) * 10.f));
            if (i == select || i == select + 1) {
                rectangle.setFillColor(sf::Color::Red);
            }
            if (i >= data.size() - done) {
                rectangle.setFillColor(sf::Color::Green);
            }
            window.draw(rectangle);
        }
                Font font("C:\\Windows\\Fonts\\Arial.ttf");
        Text text(font,"Bubble Sort \nComparisons: "+std::to_string(comparisons), 24);
        text.setFillColor(sf::Color::Black);
        text.setPosition({10.f, 10.f});
        window.draw(text);
        window.display();
    }
    



void merge(std::vector<int>& data, int left, int mid, int right, sf::RenderWindow& window, int& comparisons) {
    std::vector<int> temp;
    temp.reserve(right - left + 1);

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        comparisons++; 
        if (data[i] <= data[j]) {
            temp.push_back(data[i++]);
        } else {
            temp.push_back(data[j++]);
        }

        // snapshot for visualization
        std::vector<int> snapshot = data;
        int writeIndex = left + static_cast<int>(temp.size()) - 1;
        snapshot[writeIndex] = temp.back();
        mergedrawData(snapshot, window, left, mid, right, writeIndex, i, j, comparisons);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    while (i <= mid) {
        temp.push_back(data[i++]);
        std::vector<int> snapshot = data;
        int writeIndex = left + static_cast<int>(temp.size()) - 1;
        snapshot[writeIndex] = temp.back();
        mergedrawData(snapshot, window, left, mid, right, writeIndex, i, j, comparisons);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    while (j <= right) {
        temp.push_back(data[j++]);
        std::vector<int> snapshot = data;
        int writeIndex = left + static_cast<int>(temp.size()) - 1;
        snapshot[writeIndex] = temp.back();
        mergedrawData(snapshot, window, left, mid, right, writeIndex, i, j, comparisons);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    // merging
    for (size_t k = 0; k < temp.size(); ++k) {
        data[left + static_cast<int>(k)] = temp[k];
    }
    mergedrawData(data, window, left, mid, right, right, i, j, comparisons);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}


    void mergedrawData(const std::vector<int>& data, sf::RenderWindow& window, int left, int mid, int right, int writeIndex, int leftPtr, int rightPtr, int comparisons=0) {
        window.clear(sf::Color::White);
        const float width = 50.f;
        const float gap = 5.f;
        const float totalX = (width + gap) * static_cast<float>(data.size());
        float startX = 10.f;

        for (size_t idx = 0; idx < data.size(); ++idx) {
            float height = static_cast<float>(data[idx]) * 10.f;
            sf::RectangleShape rect(sf::Vector2f(width, height));
            rect.setPosition(sf::Vector2f(startX + static_cast<float>(idx) * (width + gap),
                                          static_cast<float>(window.getSize().y) - height));

            // default color
            rect.setFillColor(sf::Color::Blue); // blue

            // left subarray
            if (static_cast<int>(idx) >= left && static_cast<int>(idx) <= mid) {
                rect.setFillColor(sf::Color(100, 149, 237));
            }
            // right subarray
            if (static_cast<int>(idx) >= mid + 1 && static_cast<int>(idx) <= right) {
                rect.setFillColor(sf::Color::Cyan);
            }
            // already written merged portion (green)
            if (static_cast<int>(idx) >= left && static_cast<int>(idx) <= writeIndex) {
                rect.setFillColor(sf::Color::Green);
            }
            // highlight active pointers
            if (static_cast<int>(idx) == leftPtr - 1 || static_cast<int>(idx) == rightPtr - 1) {
                rect.setFillColor(sf::Color::Red);
            }
            if (static_cast<int>(idx) == writeIndex) {
                rect.setOutlineThickness(2.f);
                rect.setOutlineColor(sf::Color::Black);
            }
            window.draw(rect);
        }
        Font font("C:\\Windows\\Fonts\\Arial.ttf");
        Text text(font,"Merge Sort\nComparisons: "+std::to_string(comparisons), 24);
        text.setFillColor(sf::Color::Black);
        text.setPosition({10.f, 10.f});
        window.draw(text);
        window.display();
    }
};
int main() {
    const int dataSize = 35;
    std::vector<int> data(dataSize);
    Font font("C:\\Windows\\Fonts\\Arial.ttf");
    Text Title(font, "Sorting Algorithm Visualiser",80);
    Text subtitle(font, "CT-24146,CT-24108,CT-24116, CT-24111",24);
    subtitle.setPosition({700, 115});
    subtitle.setFillColor(sf::Color::Black);
    subtitle.setStyle(sf::Text::Underlined);
    Title.setStyle(sf::Text::Bold);
    Title.setFillColor(sf::Color::Black);
    int bubblecomp = 0;
    int insertioncomp = 0;
    int selectioncomp = 0;
    int quickcomp = 0;
    int mergecomp = 0;
    
    sf::RenderWindow window(sf::VideoMode({1920, 800}), "Sorting Algorithm Visualizer");
    SortVisualizer visualizer;
    Title.setPosition({500, 10});
    randomizeArray(data, 1, 55);
    
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            else if (event->is<sf::Event::Resized>())
            {
                window.setView(sf::View(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize()))));
            }
        }

        auto mouse_position = sf::Vector2f(sf::Mouse::getPosition(window));

        button bubblebtn(50, 150, 200, 50, font, "Bubble Sort", 24, Color::Green);
        button insertionbtn(300, 150, 200, 50, font, "Insertion Sort", 24, Color::Magenta);
        button selectionbtn(550, 150, 200, 50, font, "Selection Sort", 24, Color::Red);
        button mergebtn(800, 150, 200, 50, font, "Merge Sort", 24, Color::Cyan);
        button randomizebtn(1050, 150, 200, 50, font, "Randomize Array", 24, Color::Blue);
        button resultsbtn(1300, 150, 200, 50, font, "View Results", 24, Color::Black);

        window.clear(sf::Color::White);
        bubblebtn.draw(window);
        insertionbtn.draw(window);
        selectionbtn.draw(window);
        mergebtn.draw(window);
        randomizebtn.draw(window);
        resultsbtn.draw(window);
        drawData(data, window);
        window.draw(Title);
        window.draw(subtitle);

        if (bubblebtn.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            bubblecomp = 0;
            visualizer.bubblesort(data, window, bubblecomp);
        }
        else if (insertionbtn.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            insertioncomp=0;
            visualizer.insertionsort(data, window, insertioncomp);
        }   
        else if (selectionbtn.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            selectioncomp=0;
            visualizer.selectionsort(data, window, selectioncomp);
        }
        else if (mergebtn.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            mergecomp=0;
            std::vector<int> dataCopy = data;
            visualizer.mergesort(dataCopy, 0, static_cast<int>(data.size()) - 1, window, mergecomp);
            visualizer.drawcomplete(dataCopy, window, mergecomp);
        }
        else if (randomizebtn.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            randomizeArray(data, 1, 55);
            mergecomp = insertioncomp = selectioncomp = bubblecomp = 0;
        }
        else if (resultsbtn.isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            resultswindow(mergecomp, bubblecomp, insertioncomp, selectioncomp, "Sorting Algorithm Comparison Results");
        }

        window.display();
    }
}