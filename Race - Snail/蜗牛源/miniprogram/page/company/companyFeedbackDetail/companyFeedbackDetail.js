// miniprogram/page/company/companyFeedbackDetail/companyFeedbackDetail.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    is_pass: true,
    recieve_time: '2019-5-6',
    company_identity: '牛牛顾问助理',
    company_name: '牛牛企业管理咨询有限公司',
    apply_time: '2021-4-30',
    interview_time:'2021-5-7',
    interview_local:'上海市XXX区XXX路XXX号XXX室',
    interview_people:'筱小姐',
    phone: '130xxxxxxxxx',
    success_info : {
      title: '收到面试邀请',
      content: '恭喜你获得这次的面试机会！\n为了帮助你成功通过面试，建议你',
      button_content: '接受面试'
    },
    falied_info : {
      title : '简历不合适',
      content: '不要气馁哦！折一步还有很多职位供你选择呢！机会永远都在，再接再厉，继续加油吧！',
      button_content: '查看其它类似职位'
    }
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

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