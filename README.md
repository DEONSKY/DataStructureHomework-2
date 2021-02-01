# DataStructureHomework-2
Sakarya University Data Structure Homework 2

Ödevi geliştirmeye internetten bir araştırmayla başladım. Çünkü derste daha tüm konular işlenmemişti. Rotate right ve left fonksiyonları ve LL LR RL RR durumları biraz kafamı karıştırıyordu. Bu konuları internetten araştırdım. Örnek kodlara baktım. Ayrıca AVL ağacındaki hareketleri animasyonla gösteren bir site vardı. Bu site olan işlemleri kafamda canlandırmaya oldukça yardımcı oldu.

Uygulamayı geliştirmeye ilk başta basit bir AVL ağacı oluşturmaya çalışmakla başladım. Bu ağaç ödevde yazdığım IntAVLTree oluyor. Çünkü bu ağacın orjinalinden tek farkı eşit olan değerleri sola atması ve büyüklerin sola küçüklerin sağa kaydedilmesi. Bu ağaca birbirine yakın yada aynı veriler vererek test ettim. Rotation gereken durumları eşit olduğu durumlar için güncellemem gerekti. Bu ağacı bitirmem çok sürmedi.

Dıştaki ağaç yapısal olarak daha karmaşık. Çünkü hem içteki ağaçların root pointerlarını Nodelarında tutuyor, hem sahip olduğu değerler sürekli değiştiği için yeni değerlere göre node dizilimin de değişmesi gerekiyor. İlk başta değer güncellemesi için oldukça kafa yordum. Ama sonra fark ettim ki eğer güncellenen ExtNodu’u bulur, onu geçici bir ExtNode’ a kopyalar ve sonra ağaçtaki ExtNodu silip kopyalanıp güncellenen değeriyle yeni ExtNode’u eklemeye çalışırsam ExtAVLTree yapısı bozulmuyor. Üstelik kod çok daha anlaşılır bir algoritmaya sahip oluyor. Ve hata tespit etmek istendiği zaman her parçayı takip edip hatanın kaynağı daha kolay bulunuyor.

Şimdi programın işleyişini anlatayım. ExtAVLTree’nin 2 adet insert fonksiyonu var. İlkinin görevi kullanıcıyı ExtAVLTree nin root bilgisinden soyutlamak, diğeri ise insert işlemi için gerekli fonkları root, corp, name ve date bilgilerini alarak çağırıyor. İlk başta SearchInsert fonksiyonuyla daha önce aynı şirketin kaydı var mı diye bakıyor. Eğer yoksa null dönüyor. Eğer şirket ismini bulursa gerekli güncelleme işlemini yapıp tüm bilgileri Insert fonkunun içinde geçici olarak oluşturulan tempExtNode pointerına döndürüyor. Ama bulduğu an hemen geri dönmüyor. Çünkü aslında diğer görevi de ağaç içinde gezip tüm balanceları delete işlemi öncesi güncellemek. Bu fonksiyonu yazarken postOrder’dan ilham aldım.
Bu işlem bittikten sonra bulamamışsa ilk ExtNode’u oluşturuyor yada bulmuşsa, bulunan ExtNode’u silip güncellenmiş halini Insert ediyor.

Delete fonku performans kazanmak için silinecek ExtNode’un count değerine ya sola ya sağa ya da eşit olan durumlarda balance sonrası eşit sayılar sağa geçebileceği için hem solu hem sağı kontrol ediyor. Ve Şirket ismini bulunca da silip, ballance bozulmuşsa ExtNodeları ballance a sokuyor.

Delete işlemi bittikten sonra InsertNode fonksiyonu, güncellenmiş ExtNodu eleman sayısına göre uygun yere ekliyor. Ama eklenen node balance’ı bozabilir. Bu yüzden balance’ı kontrol ediyor. Eğer bozulumuşsa. LL RL LR RR işlemelerinden uygun olanıyla balanca’a sokuyor. Bu sayede yeni değer ekleme işlemi bitmiş oluyor.

Dosya okuma kısmını en son hallettim. Bundan önceki ödevde kullandığım kodun aynısını modifiye edip kullandım. Her satırı okurken bileşenleri # sembolüne göre ayrıp satır sonununda ExtAVLTree’nin insert fonksiyonuna gönderiyor. Insert fonksiyonu da bu bilgilerden yararlanarak gerekli işlemleri gerçekleştiriyor.
