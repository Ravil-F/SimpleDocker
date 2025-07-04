# Simple Docker


## Part 1. Готовый докер

- Возьми официальный докер-образ с nginx и выкачай его при помощи docker pull: 
    - запустим докер
    - в командной строке вводим команду: docker pull nginx\
    ![Part1](pictures/Part_1/1.png)

- Проверь наличие докер-образа через docker images:
    - в командной строке вводим команду: docker images\
    ![Part1](pictures/Part_1/2.png)
- Запусти докер-образ через docker run -d [image_id|repository]
    - в командной строке вводим команду: docker run -d nginx\
    ![Part1](pictures/Part_1/3.png)

- Проверь, что образ запустился через docker ps:
    - в командной строке вводим команду: docker ps\
    ![Part1](pictures/Part_1/4.png)

- Посмотри информацию о контейнере через docker inspect [container_id|container_name]:
    - в командной строке вводим команду: docker inspect 23fd622334b2 | charming_saha\
    ![Part1](pictures/Part_1/5_1.png)\
    ![Part1](pictures/Part_1/5_2.png)\
    ![Part1](pictures/Part_1/5_3.png)

- По выводу команды определи и помести в отчёт размер контейнера, список замапленных портов и ip контейнера:
    - размер контейнера: ShmSize: 67108864
    - список замапленных портов: "Ports": { "80/tcp": null }
    - ip контейнера: "IPAddress": "172.17.0.2"

- Останови докер контейнер через docker stop [container_id|container_name]:
    - в командной строке вводим команду: docker stop 23fd622334b2 | charming_saha\
    ![Part1](pictures/Part_1/6.png)

- Проверь, что контейнер остановился через docker ps:
     - в командной строке вводим команду: docker ps | docker ps -a\
    ![Part1](pictures/Part_1/7.png)

- Запусти докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду run:
    - в командной строке вводим команду: docker run -d -p 80:80 -p 443:443 nginx\
    ![Part1](pictures/Part_1/8.png)

- Проверь, что в браузере по адресу localhost:80 доступна стартовая страница nginx:
    - в командной строке вводим команду: curl localhost:80\
    ![Part1](pictures/Part_1/9_1.png)  
    или в браузере localhost:80\
    ![Part1](pictures/Part_1/9_2.png)

- Перезапусти докер контейнер через docker restart [container_id|container_name]:
    - командой docker ps посмотрим его id | name:\
    ![Part1](pictures/Part_1/10_1.png)
    - командa: docker restart distrasted_clarke\
    ![Part1](pictures/Part_1/10_2.png)

- Проверь любым способом, что контейнер запустился:
    - команда docker ps\
    ![Part1](pictures/Part_1/11.png)



## Part 2. Операции с контейнером

- Прочитай конфигурационный файл nginx.conf внутри докер контейнера через команду exeс:
    - используем команду: docker exec -it [container_name] cat /etc/nginx/nginx.conf\
    ![Part2](pictures/Part_2/1.png)

- Создай на локальной машине файл nginx.conf:\      
    ![Part2](pictures/Part_2/2.png)

- Настрой в нем по пути /status отдачу страницы статуса сервера nginx:
    - используем любой редактор\
    ![Part2](pictures/Part_2/3.png)

- Скопируй созданный файл nginx.conf внутрь докер-образа через команду docker cp
    - комадна docker cp nginx.conf [container_id|container_name]:/etc/nginx/nginx.conf\
    ![Part2](pictures/Part_2/4.png)

- Перезапусти nginx внутри докер-образа через команду exec:
    - docker exec [container_id|container_name] nginx -s reload\
    ![Part2](pictures/Part_2/5.png)

- Проверь, что по адресу localhost:80/status отдается страничка со статусом сервера nginx:\
    ![Part2](pictures/Part_2/6.png)

- Экспортируй контейнер в файл container.tar через команду export:
    - команда docker export [container_id|container_name] > container.tar\
    ![Part2](pictures/Part_2/7.png)

- Останови контейнер:\
    ![Part2](pictures/Part_2/8.png)

- Удали образ через docker rmi -f [image_id|repository], не удаляя перед этим контейнеры:
    - команда docker rmi -f nginx\
    ![Part2](pictures/Part_2/9.png)

- Удали остановленный контейнер:
    - команда docker rm [container_id|container_name]\
    ![Part2](pictures/Part_2/10.png)

- Импортируй контейнер обратно через команду import (docker import [OPTIONS] file|URL|- [REPOSITORY[:TAG]]):
    - команда docker import -c 'cmd ["nginx", "-g", "daemon off;"]' container.tar nginx\
    ![Part2](pictures/Part_2/11.png)

- Запусти импортированный контейнер:
    - команда docker run -d -p 80:80 -p 443:443 nginx\
    ![Part2](pictures/Part_2/12.png)

- Проверь, что по адресу localhost:80/status отдается страничка со статусом сервера nginx:\
    ![Part2](pictures/Part_2/13.png)


## Part 3. Мини веб-сервер

- Напиши мини-сервер на C и FastCgi, который будет возвращать простейшую страничку с надписью Hello World!\  
    ![Part3](pictures/Part_3/1.png)

- Исправляем nginx.conf, и копируем в /etc/nginx/nginx.conf\
    ![Part3](pictures/Part_3/2.png)

- Заходим в контейнер и запускаем нужное ПО:\
    ![Part3](pictures/Part_3/3.png)
    ![Part3](pictures/Part_3/4.png)

- Компилируем и запускаем мини-сервер, перезапускаем nginx :\
    ![Part3](pictures/Part_3/5.png)

- Проверяем через браузер: localhost:81 :\
    ![Part3](pictures/Part_3/6.png)

- Положим файл nginx.conf по пути ./nginx/nginx.conf:\
    ![Part3](pictures/Part_3/7.png)


## Part 4. Свой докер

- Создаем Dockerfile:
    - cоздаем файл run.sh, пишем скрипт для запуска сервера, старта образа:\
    ![Part4](pictures/Part_4/1.png)
    - собираем исходники мини-сервера на FastCgi, написанного из Part_3
    - запускает его на 8080 порту
    - копирует внутрь образа написанный ./nginx/nginx.conf
    - запускает nginx\
    ![Part4](pictures/Part_4/2.png)

- Собери написанный докер-образ через docker build при этом указав имя и тег. Должны находиться, где  Dockerfile (Имя указываешь любой):\
    ![Part4](pictures/Part_4/3.png)

- Проверь через docker images, что все собралось корректно:\
    ![Part4](pictures/Part_4/4.png)

- Запусти собранный докер-образ с маппингом 81 порта на 80 на локальной машине и маппингом папки ./nginx внутрь контейнера по адресу, где лежат конфигурационные файлы nginx'а (см. Часть 2):\
    ![Part4](pictures/Part_4/5.png)

- Проверь, что по localhost:80 доступна страничка написанного мини сервера:\
    ![Part4](pictures/Part_4/6.png)

- Допиши в ./nginx/nginx.conf проксирование странички /status, по которой надо отдавать статус сервера nginx:
    - добавляем код в nginx.conf:\
        ![Part4](pictures/Part_4/7.png)
    - Перезапустим докер-образ, docker restart [CONTAINER ID][NAMES]:\
        ![Part4](pictures/Part_4/8.png)

- Проверь, что теперь по localhost:80/status отдается страничка со статусом nginx:\
    ![Part4](pictures/Part_4/9.png)


## Part 5. Dockle

- Просканируй образ из предыдущего задания через dockle [image_id|repository]:\
    - перед этим установим утилиту dockle - brew install goodwithtech/r/dockle:\
        ![Part5](pictures/Part_5/1.png)
    - сохраняем наш образ в container.tar через команду docker save [REPOSITORY]:[TAG] -o [name.tar] (без этого не можем посмотреть ошибку):\
        ![Part5](pictures/Part_5/2.png)
    - проверяем dockle --input [name].tar:\
        ![Part5](pictures/Part_5/3.png)

-  исправляем ошибки в Dockerfile:\
    ![Part5](pictures/Part_5/4.png)

- Перезапустим докер-образ, docker restart [CONTAINER ID][NAMES]:\
    ![Part5](pictures/Part_5/5.png)

- сохраняем образ, проверяем dockle --input [name].tar:\
    ![Part5](pictures/Part_5/6.png)


## Part 6. Базовый Docker Compose

- Установим docker-compose - командой brew install docker-compose:\
    ![Part6](pictures/Part_6/1.png)

- Напиши файл docker-compose.yml, с помощью которого:
    - Подними докер-контейнер из Части 5 (он должен работать в локальной сети, т.е. не нужно использовать инструкцию EXPOSE и мапить порты на локальную машину);
    - Подними докер-контейнер с nginx, который будет проксировать все запросы с 8080 порта на 81 порт первого контейнера;
    - Замапь 8080 порт второго контейнера на 80 порт локальной машины:\
     ![Part6](pictures/Part_6/2.png)\
     ![Part6](pictures/Part_6/3.png)
    - Для второго образа так же пишем Dockerfile:\
     ![Part6](pictures/Part_6/4.png)

- Останови все запущенные контейнеры: docker stop [name]

- Собери и запусти проект с помощью команд docker-compose build и docker-compose up:\
    ![Part6](pictures/Part_6/5.png)
    ![Part6](pictures/Part_6/6.png)

- Проверь, что в браузере по localhost:80 отдается написанная тобой страничка, как и ранее:\
    ![Part6](pictures/Part_6/7.png)
    ![Part6](pictures/Part_6/8.png)