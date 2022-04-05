// miniprogram/page/normal/normalGoods/normalGoods.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    index:1,
    goods:[],
    selected:{},
    totalMoney:0,
    good:{
      count:1
    },
    cateItems: [
      {
        cate_id: 1,
        cate_name: '手工竹编',
      },
      {
        cate_id: 2,
        cate_name: '陶瓷故事',
      },
      {
        cate_id: 3,
        cate_name: '品藤编'
      },
      {
        cate_id: 4,
        cate_name: '手工木编'
      },
      {
        cate_id: 5,
        cate_name: '茶道类'
      },
      {
        cate_id: 6,
        cate_name: '居家日用类'
      },
      {
        cate_id: 7,
        cate_name: '居家整理类'
      },
      {
        cate_id: 8,
        cate_name: '餐饮具类'
      },
    ],
    curNav: 1,
    curIndex: 0,
    curName:"手工竹编",
    showDialog:false,
    all_works:[
      
    ]
  },
  switchRightTab: function (e) {
    let id = e.target.dataset.id, index = e.target.dataset.index;
    let name = e.target.dataset.name
    this.setData({
      curNav: id,
      curIndex: index,
      curName: name
    })
    this.getByType(this.data.curName)
  },
  getByType(type){
    var that = this
    wx.request({
      url: 'http://localhost:8080/artistWork/getByType',
      data:{
        type:type
      },
      method:'GET',
      success:function(res){
        that.setData({
          goods: res.data.data
        })
        console.log(res.data.data)
        console.log(that.data.goods)
      }
    })
  },
  goShopping(){
    wx.navigateTo({
      url: '../normalShopping/normalShopping',
    })
  },
  toggleDialog: function (e) {
    var that = this
    console.log(e.currentTarget.dataset.id)
    var s = e.currentTarget.dataset.id
    that.setData({
      showDialog: !this.data.showDialog,
      selected:s,
      totalMoney:s.price
    });
  },
  closeDialog: function () {
    console.info("关闭");
    this.data.good.count=1
    this.setData({
      showDialog: false,
      good:this.data.good
    });
  },
  delCount: function (e) {
    console.log("刚刚您点击了减1");
    var count = this.data.good.count;
    // 商品总数量-1
    if (count > 1) {
      this.data.good.count--;
    }
    // 将数值与状态写回  
    this.priceCount();
  },
  /* 加数 */
  addCount: function (e) {
    console.log("刚刚您点击了加1");
    var count = this.data.good.count;
    // 商品总数量-1  
    if (count < 10) {
      this.data.good.count++;
    }
    // 将数值与状态写回  
    this.priceCount();
  },
  priceCount: function (e) {
    this.data.totalMoney = this.data.selected.price * this.data.good.count;
    this.setData({
      good: this.data.good,
      totalMoney:this.data.totalMoney
    })
  },
  addCar(){
    wx.showToast({
      title: '加入购物车成功！',
      icon: 'success',
      duration: 2000
    });
    this.closeDialog(); 
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    var that = this
    this.getByType(that.data.curName)
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})